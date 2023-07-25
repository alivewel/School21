-- Part 2. Изменение данных
-- Task1. Написать процедуру добавления P2P проверки.

-- Параметры: ник проверяемого, ник проверяющего, название задания, статус P2P проверки, время.
CREATE OR REPLACE PROCEDURE INSERT_P2P_CHECK
(CHECKINGPEER VARCHAR, CHECKEDPEER VARCHAR, TASK_PARAM VARCHAR, STATE CheckStatus, Time_ TIME )
LANGUAGE plpgsql
AS $$
BEGIN
    CASE 
        WHEN STATE = 'Start' THEN
            INSERT INTO CHECKS
            VALUES (
                (SELECT MAX(id) + 1 FROM CHECKS),
                CHECKINGPEER,
                TASK_PARAM,
                CURRENT_DATE
            );
            INSERT INTO P2P
            VALUES (
                (SELECT MAX(id) + 1 FROM P2P),
                (SELECT MAX(id) FROM CHECKS),
                CHECKEDPEER,
                STATE,
                Time_
            );
        ELSE
            INSERT INTO P2P
            VALUES (
                (SELECT MAX(id) + 1 FROM P2P),
                (SELECT MAX(id) FROM CHECKS CH WHERE CH.PEER = CHECKINGPEER AND TASK_PARAM = CH.TASK),
                CHECKEDPEER,
                STATE,
                Time_
            );
    END CASE;
END;
$$;

-- INSERT INTO P2P VALUES ( (SELECT MAX(id) + 1 FROM P2P), (SELECT MAX(id) FROM CHECKS), 'lopata', 'Success', '09:33:33');
-- DROP PROCEDURE IF EXISTS INSERT_P2P_CHECK(character varying, character varying, character varying, statuschecks, time without time zone);

CALL INSERT_P2P_CHECK('bolondos', 'ereman', 'C6_s21_matrix', 'Start', '12:34:56');
CALL INSERT_P2P_CHECK('bolondos', 'ereman', 'C6_s21_matrix', 'Success', '12:34:56');

CALL INSERT_P2P_CHECK('lopata', 'amongus', 'C7_SmartCalc_v1.0', 'Start', '16:33:57');
CALL INSERT_P2P_CHECK('lopata', 'amongus', 'C7_SmartCalc_v1.0', 'Success', '16:33:57');

-- Task2. Написать процедуру добавления проверки Verter'ом

-- Параметры: ник проверяющего, название задания, статус проверки Verter'ом, время.
CREATE OR REPLACE PROCEDURE INSERT_VERTER_CHECK
(CHECKINGPEER VARCHAR, TASK_PARAM VARCHAR, STATE CheckStatus, Time_ TIME)
LANGUAGE plpgsql
AS $$
BEGIN
    INSERT INTO VERTER (ID, Check_, State_, Time_)
    VALUES (
        (SELECT MAX(id) + 1 FROM VERTER),
        (SELECT MAX(id) FROM CHECKS CH WHERE CH.PEER = CHECKINGPEER AND TASK_PARAM = CH.TASK),
        STATE,
        Time_
    );
END;
$$;

CALL INSERT_VERTER_CHECK('bolondos', 'C6_s21_matrix', 'Start', '12:34:56');
CALL INSERT_VERTER_CHECK('bolondos', 'C6_s21_matrix', 'Success', '12:34:56');

CALL INSERT_VERTER_CHECK('lopata', 'C6_s21_matrix', 'Start', '16:33:57');
CALL INSERT_VERTER_CHECK('lopata', 'C6_s21_matrix', 'Success', '16:33:57');
-- DROP PROCEDURE IF EXISTS INSERT_VERTER_CHECK;

-- Task3. Написать триггер: после добавления записи со статутом "начало" в таблицу P2P, изменить соответствующую запись в таблице TransferredPoints

CREATE OR REPLACE FUNCTION fnc_trg_p2p_insert_transferredpoints() RETURNS TRIGGER AS $$
BEGIN
    IF NEW.state_ = 'Start' THEN
        UPDATE TransferredPoints
        SET pointsamount = pointsamount + 1
        WHERE CheckingPeer = NEW.CheckingPeer
        AND CheckedPeer IN (
            SELECT checks.peer
            FROM checks
            INNER JOIN p2p ON p2p.check_ = checks.id
            WHERE p2p.check_ = NEW.check_
        );
        RETURN NEW;
    ELSE
        RETURN NULL;
    END IF;
END;
$$ LANGUAGE plpgsql;


CREATE TRIGGER trg_p2p_insert_transferredpoints
AFTER INSERT ON P2P
FOR EACH ROW EXECUTE PROCEDURE fnc_trg_p2p_insert_transferredpoints();


CALL INSERT_P2P_CHECK('dushnila', 'lopata', 'C6_s21_matrix', 'Start', '12:34:56');
CALL INSERT_P2P_CHECK('dushnila', 'lopata', 'C6_s21_matrix', 'Success', '12:34:56');


-- Удаление триггера
DROP TRIGGER IF EXISTS trg_p2p_insert_transferredpoints ON TransferredPoints;

-- Удаление функции
DROP FUNCTION IF EXISTS fnc_trg_p2p_insert_transferredpoints() CASCADE;

-- Удаление таблицы
DELETE FROM TransferredPoints;

-- Task4. Написать триггер: перед добавлением записи в таблицу XP, проверить корректность добавляемой записи

CREATE OR REPLACE FUNCTION fnc_trg_insert_xp() RETURNS TRIGGER AS $$
BEGIN
    -- Проверка максимального количества XP для задачи
    IF (SELECT maxxp FROM tasks
        INNER JOIN checks on tasks.title = checks.task
        WHERE checks.id = NEW.check_) < NEW.XPAmount THEN
        RAISE EXCEPTION 'Превышено максимальное количество XP для задачи';
    END IF;
    -- Проверка наличия успешной проверки по полю Check
    IF NOT EXISTS (SELECT 1 FROM Checks
                   INNER JOIN verter on checks.id = verter.check_
                   WHERE Checks.id = NEW.check_ AND
                   verter.state_ = 'Success') THEN
        RAISE EXCEPTION 'Неверная ссылка на успешную проверку';
    END IF;

    RETURN NEW;
EXCEPTION
    WHEN OTHERS THEN
        -- Ловим исключения и отменяем добавление записи
        RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_insert_xp
BEFORE INSERT ON XP
FOR EACH ROW EXECUTE FUNCTION fnc_trg_insert_xp();

-- Удаление триггера
DROP TRIGGER IF EXISTS trg_insert_xp ON XP;
-- Удаление функции
DROP FUNCTION IF EXISTS fnc_trg_insert_xp() CASCADE;

INSERT INTO XP VALUES ((SELECT MAX(id) + 1 FROM XP), 9, 250);

DELETE FROM XP WHERE id = (SELECT MAX(id) FROM XP);





