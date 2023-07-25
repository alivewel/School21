-- Part 4. Метаданные

-- Task1. Создать хранимую процедуру, которая, не уничтожая базу данных, уничтожает все те таблицы
-- текущей базы данных, имена которых начинаются с фразы 'TableName'.

DROP TABLE IF EXISTS
    TableName_1, TableName_2;


CREATE TABLE TableName_1
(
    ID       SERIAL PRIMARY KEY,
    Nickname VARCHAR(255) NOT NULL
);

CREATE TABLE TableName_2
(
    ID   SERIAL PRIMARY KEY,
    Name VARCHAR(255) NOT NULL
);

-- DROP PROCEDURE IF EXISTS drop_table;
CREATE OR REPLACE PROCEDURE drop_table(name_of_table TEXT)
    LANGUAGE PLPGSQL AS
$$
DECLARE
    tbl_name RECORD;
BEGIN
    FOR tbl_name IN
        (
            SELECT table_name
            FROM information_schema.tables ist
            WHERE table_schema = 'public'
              AND ist.table_name SIMILAR TO concat(name_of_table, '%')
        )
        LOOP
            EXECUTE format('DROP TABLE IF EXISTS %I CASCADE', tbl_name.table_name);
            RAISE INFO 'Dropped table: %', tbl_name.table_name;
        END LOOP;
END;
$$;

CALL drop_table('tablename');


--Task2. Создать хранимую процедуру с выходным параметром, которая выводит список имен и параметров всех
-- скалярных SQL функций пользователя в текущей базе данных. Имена функций без параметров не выводить.
-- Имена и список параметров должны выводиться в одну строку. Выходной параметр возвращает количество
-- найденных функций.

-- DROP FUNCTION IF EXISTS function_without_param;
CREATE OR REPLACE FUNCTION function_without_param()
    RETURNS VOID
    LANGUAGE plpgsql
AS
$$
BEGIN
    RAISE INFO 'called function_without_param';
END;
$$;

-- SELECT *
-- FROM function_without_param();

--  DROP FUNCTION IF EXISTS function_with_one_param;
CREATE OR REPLACE FUNCTION function_with_one_param(arg1 TEXT)
    RETURNS VOID
    LANGUAGE plpgsql
AS
$$
BEGIN
    RAISE INFO 'called function_with_one_param %', arg1;
END;
$$;

-- SELECT *
-- FROM function_with_one_param('TEST WITH FUN 1');

-- DROP FUNCTION IF EXISTS function_with_two_param;
CREATE OR REPLACE FUNCTION function_with_two_param(arg1 TEXT, arg2 TEXT)
    RETURNS VOID
    LANGUAGE plpgsql
AS
$$
BEGIN
    RAISE INFO 'called function_with_one_param % %', arg1, arg2;
END;
$$;

-- SELECT *
-- FROM function_with_two_param('TEST WITH FUN 2', 'TEST WITH FUN 2');
--

--DROP PROCEDURE IF EXISTS count_function_with_param;
CREATE OR REPLACE PROCEDURE count_function_with_param(OUT func_with_param_count INT)
    LANGUAGE PLPGSQL AS
$$
DECLARE
    func_rec RECORD;
BEGIN
    func_with_param_count := 0;

    FOR func_rec IN
        (
            SELECT proname AS name, prokind As type, proargnames
            FROM pg_proc
            WHERE prokind = 'f'
              AND pronamespace = (SELECT oid FROM pg_namespace WHERE nspname = 'public')
              AND proargnames IS NOT NULL
        )
        LOOP
            func_with_param_count := func_with_param_count + 1;
        END LOOP;
END;
$$;


CALL count_function_with_param(NULL);


-- Task3. Создать хранимую процедуру с выходным параметром, которая уничтожает все SQL DML триггеры
-- в текущей базе данных. Выходной параметр возвращает количество уничтоженных триггеров.

DROP TRIGGER IF EXISTS after_insert_trigger ON peers;

CREATE OR REPLACE FUNCTION trigger_function()
    RETURNS TRIGGER AS
$$
BEGIN
    RAISE INFO 'Trigger for test';
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER after_insert_p2p
    AFTER INSERT
    ON peers
    FOR EACH ROW
EXECUTE FUNCTION trigger_function();

--   SELECT trigger_name, event_object_table
--             FROM information_schema.triggers
--             WHERE trigger_schema = 'public'

--DROP PROCEDURE IF EXISTS drop_dml_triggers;
CREATE OR REPLACE PROCEDURE drop_dml_triggers(OUT trigger_count INT)
    LANGUAGE PLPGSQL AS
$$
DECLARE
    trigger_rec RECORD;
BEGIN
    trigger_count := 0;

    FOR trigger_rec IN
        (
            SELECT trigger_name, event_object_table
            FROM information_schema.triggers
            WHERE trigger_schema = 'public'
        )
        LOOP
            EXECUTE format('DROP TRIGGER IF EXISTS %I ON %s.%s', trigger_rec.trigger_name, 'public',
                           trigger_rec.event_object_table);
            trigger_count := trigger_count + 1;
        END LOOP;
END;
$$;

CALL drop_dml_triggers(NULL);


--Task4. Создать хранимую процедуру с входным параметром, которая выводит имена и описания типа
-- объектов (только хранимых процедур и скалярных функций), в тексте которых на языке SQL встречается строка, задаваемая параметром процедуры.

--DROP PROCEDURE IF EXISTS find_function_and_procedure_with_text;
CREATE OR REPLACE PROCEDURE find_function_and_procedure_with_text(search_text TEXT, RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        SELECT proname AS name, (CASE WHEN prokind = 'f' THEN 'Function' ELSE 'Procedure' END) AS type
        FROM pg_proc
        WHERE prokind IN ('f', 'p')
          AND prosrc SIMILAR TO concat('%' || search_text || '%')
          AND pronamespace = (SELECT oid FROM pg_namespace WHERE nspname = 'public');
END;
$$;

COMMIT;
BEGIN;
CALL find_function_and_procedure_with_text('', 'RESULT');
FETCH ALL IN "RESULT";
END;
