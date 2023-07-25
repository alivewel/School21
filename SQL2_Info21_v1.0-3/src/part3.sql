-- Part 3. Получение данных

-- Task1. Написать функцию, возвращающую таблицу TransferredPoints в более человекочитаемом виде
-- Ник пира 1, ник пира 2, количество переданных пир поинтов.
-- Количество отрицательное, если пир 2 получил от пира 1 больше поинтов.


-- DROP FUNCTION get_transferred_points_readable();
CREATE OR REPLACE FUNCTION get_transferred_points_readable()
    RETURNS TABLE
            (
                "Peer1"        VARCHAR(255),
                "Peer2"        VARCHAR(255),
                "PointsAmount" INT
            )
    LANGUAGE plpgsql
AS
$$
BEGIN
    RETURN QUERY
        SELECT tp1.checkingpeer,
               tp1.checkedpeer,
               CASE
                   WHEN (
                            SELECT tp2.pointsamount
                            FROM transferredpoints AS tp2
                            WHERE tp1.checkingpeer = tp2.checkedpeer
                              AND tp1.checkedpeer = tp2.checkingpeer
                        ) > tp1.pointsamount THEN -(tp1.pointsamount)
                   ELSE tp1.pointsamount
                   END
        FROM transferredpoints AS tp1;
END;
$$;

SELECT *
FROM get_transferred_points_readable();

-- Task2. Написать функцию, которая возвращает таблицу вида: ник пользователя, название проверенного задания, кол-во полученного XP
-- В таблицу включать только задания, успешно прошедшие проверку (определять по таблице Checks).
-- Одна задача может быть успешно выполнена несколько раз. В таком случае в таблицу включать все успешные проверки.

-- DROP FUNCTION get_peer_success_task_and_xp();
CREATE OR REPLACE FUNCTION get_peer_success_task_and_xp()
    RETURNS TABLE
            (
                "Peer" VARCHAR(255),
                "Task" VARCHAR(255),
                "XP"   INT
            )
    LANGUAGE plpgsql
AS
$$
BEGIN
    RETURN QUERY
        SELECT ch.peer, ch.task, xp.xpamount
        FROM checks AS ch
                 INNER JOIN xp ON ch.id = xp.check_
                 INNER JOIN p2p ON ch.id = p2p.check_
                 INNER JOIN verter ON ch.id = verter.check_
        WHERE xp.xpamount > 0
          AND p2p.state_ = 'Success'
          AND verter.state_ = 'Success';
END;
$$;

SELECT *
FROM get_peer_success_task_and_xp();

-- Task3. Написать функцию, определяющую пиров, которые не выходили из кампуса в течение всего дня
-- Параметры функции: день, например 12.05.2022.
-- Функция возвращает только список пиров.

-- DROP FUNCTION find_peers_not_lest_campus_for_day();
CREATE OR REPLACE FUNCTION find_peers_not_lest_campus_for_day(day DATE)
    RETURNS SETOF VARCHAR(255)
    LANGUAGE plpgsql
AS
$$
BEGIN
    RETURN QUERY
        SELECT DISTINCT peer
        FROM timetracking
        WHERE date_ = day
        GROUP BY peer, date_
        HAVING SUM(state_) = 3;
END;
$$;


SELECT *
FROM find_peers_not_lest_campus_for_day('2023-06-25');


-- Task4. Посчитать изменение в количестве пир поинтов каждого пира по таблице TransferredPoints
-- Результат вывести отсортированным по изменению числа поинтов.
-- Формат вывода: ник пира, изменение в количество пир поинтов

-- DROP FUNCTION calculate_change_peer_points();
CREATE OR REPLACE FUNCTION calculate_change_peer_points()
    RETURNS TABLE
            (
                "Peer"         VARCHAR(255),
                "PointsChange" BIGINT
            )
    LANGUAGE plpgsql
AS
$$
BEGIN
    RETURN QUERY
        SELECT COALESCE(t1.checkingpeer, t2.checkedpeer)                             AS Peer,
               COALESCE(SUM(t1.pointsamount), 0) - COALESCE(SUM(t2.pointsamount), 0) AS PointsChange
        FROM transferredpoints AS t1
                 FULL JOIN transferredpoints AS t2
                           ON t1.checkedpeer = t2.checkingpeer AND t1.checkingpeer = t2.checkedpeer
        GROUP BY COALESCE(t1.checkingpeer, t2.checkedpeer)
        ORDER BY 2 DESC;
END;
$$;


SELECT *
FROM calculate_change_peer_points();

-- Task5. Посчитать изменение в количестве пир поинтов каждого пира
-- по таблице, возвращаемой первой функцией из Part 3
-- Результат вывести отсортированным по изменению числа поинтов.
-- Формат вывода: ник пира, изменение в количество пир поинтов


-- DROP FUNCTION calculate_change_peer_points_task5();
CREATE OR REPLACE FUNCTION calculate_change_peer_points_task5()
    RETURNS TABLE
            (
                "Peer"         VARCHAR(255),
                "PointsChange" BIGINT
            )
    LANGUAGE plpgsql
AS
$$
BEGIN
    RETURN QUERY
        SELECT COALESCE(t1."Peer1", t2."Peer2")                                          AS Peer,
               COALESCE(SUM(t1."PointsAmount"), 0) - COALESCE(SUM(t2."PointsAmount"), 0) AS PointsChange
        FROM get_transferred_points_readable() AS t1
                 FULL JOIN get_transferred_points_readable() AS t2
                           ON t1."Peer1" = t2."Peer2" AND t1."Peer2" = t2."Peer1"
        GROUP BY COALESCE(t1."Peer1", t2."Peer2")
        ORDER BY 2 DESC;
END;
$$;


SELECT *
FROM calculate_change_peer_points_task5();

-- Task6. Определить самое часто проверяемое задание за каждый день
-- При одинаковом количестве проверок каких-то заданий в определенный день, вывести их все.
-- Формат вывода: день, название задания

-- DROP FUNCTION find_most_checked_task_for_each_day();
CREATE OR REPLACE FUNCTION find_most_checked_task_for_each_day()
    RETURNS TABLE
            (
                "Day"  DATE,
                "Task" VARCHAR(255)
            )
    LANGUAGE plpgsql
AS
$$
BEGIN
    RETURN QUERY
        SELECT date_, Task
        FROM (
                 SELECT Date_, Task, RANK() OVER (PARTITION BY Date_ ORDER BY COUNT(*) DESC) AS rnk
                 FROM Checks
                 GROUP BY Date_, Task
             ) AS groups
        WHERE rnk = 1;
END;
$$;


SELECT *
FROM find_most_checked_task_for_each_day();

-- Task7. Найти всех пиров, выполнивших весь заданный блок задач и дату завершения последнего задания
-- Параметры процедуры: название блока, например "CPP".
-- Результат вывести отсортированным по дате завершения.
-- Формат вывода: ник пира, дата завершения блока (т.е. последнего выполненного задания из этого блока)

CREATE OR REPLACE PROCEDURE find_peers_done_block_of_task(block_name TEXT, RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        SELECT ch.peer, ch.date_ AS Day
        FROM checks AS ch
                 JOIN p2p ON ch.id = p2p.check_
                 JOIN verter ON ch.id = verter.check_
        WHERE p2p.state_ = 'Success'
          AND (verter.state_ = 'Success' OR verter.state_ IS NULL)
          AND ch.task = (SELECT MAX(title)
                         FROM tasks
                         WHERE title SIMILAR TO concat(block_name, '[0-9]%'))
        ORDER BY Day DESC;
END;
$$;


commit;
BEGIN;
CALL find_peers_done_block_of_task('C', 'RESULT');
FETCH ALL IN "RESULT";
END;

--Task8. Определить, к какому пиру стоит идти на проверку каждому обучающемуся
-- Определять нужно исходя из рекомендаций друзей пира, т.е. нужно найти пира, проверяться у которого рекомендует наибольшее число друзей.
-- Формат вывода: ник пира, ник найденного проверяющего

-- DROP FUNCTION find_peer_to_go_for_check();
CREATE OR REPLACE FUNCTION find_peer_to_go_for_check()
    RETURNS TABLE
            (
                "Peer"            VARCHAR(255),
                "RecommendedPeer" VARCHAR(255)
            )
    LANGUAGE plpgsql
AS
$$
BEGIN
    RETURN QUERY
        WITH all_peer AS (SELECT p.nickname, (CASE WHEN nickname = f.peer1 THEN peer2 ELSE peer1 END) AS friend
                          FROM peers p
                                   JOIN friends f ON p.nickname = f.peer1 OR p.nickname = f.peer2),
             recommend_peer AS (
                 SELECT nickname, rc.recommendedpeer, COUNT(rc.recommendedpeer) AS rec_count
                 FROM all_peer
                          JOIN recommendations AS rc ON rc.peer = all_peer.friend
                 WHERE all_peer.nickname != rc.recommendedpeer
                 GROUP BY nickname, rc.recommendedpeer
             ),
             max_recommend AS (
                 SELECT nickname, MAX(rec_count) AS max_count
                 FROM recommend_peer
                 GROUP BY nickname
             )

        SELECT rp.nickname AS peer, rp.recommendedpeer
        FROM recommend_peer rp
                 JOIN max_recommend mr ON mr.nickname = rp.nickname AND mr.max_count = rp.rec_count;

END;
$$;


SELECT *
FROM find_peer_to_go_for_check();



-- Task9. Определить процент пиров, которые:
-- Приступили только к блоку 1
-- Приступили только к блоку 2
-- Приступили к обоим
-- Не приступили ни к одному

CREATE OR REPLACE PROCEDURE pd_get_started_tasks(p_filter1 TEXT, p_filter2 TEXT, RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        SELECT
            ot.only_tasks1 AS "StartedBlock1",
            ot2.only_tasks2 AS "StartedBlock2",
            t1_and_t2.tasks1_and_tasks2 AS "StartedBothBlocks",
            n_d.not_started AS "DidntStartAnyBlock"
        FROM
            (SELECT COUNT(DISTINCT c1.peer) * 100 / (SELECT COUNT(*) FROM peers) AS only_tasks1
             FROM checks c1
             WHERE c1.task LIKE p_filter1
                 AND NOT EXISTS (
                     SELECT 1
                     FROM checks c2
                     WHERE c1.peer = c2.peer AND c2.task NOT LIKE p_filter1
                 )) ot,
            (SELECT COUNT(DISTINCT c1.peer) * 100 / (SELECT COUNT(*) FROM peers) AS only_tasks2
             FROM checks c1
             WHERE c1.task LIKE p_filter2
                 AND NOT EXISTS (
                     SELECT 1
                     FROM checks c2
                     WHERE c1.peer = c2.peer AND c2.task NOT LIKE p_filter2
                 )) ot2,
            (SELECT COUNT(DISTINCT peer) * 100 / (SELECT COUNT(*) FROM peers) AS tasks1_and_tasks2
            FROM (
                SELECT peer
                FROM checks
                WHERE task LIKE p_filter1
                INTERSECT
                SELECT peer
                FROM checks
                WHERE task LIKE p_filter2
            ) t1_t2
            ) t1_and_t2,
            (SELECT COUNT(*) * 100 / (SELECT COUNT(*) FROM peers) AS not_started
            FROM peers p
            WHERE NOT EXISTS (
                SELECT 1
                FROM checks c
                WHERE p.nickname = c.peer
            )) n_d;
END;
$$;

BEGIN;
    CALL pd_get_started_tasks('D%', 'C%', 'RESULT');
    FETCH ALL IN "RESULT";
END;

-- Task10.Определить процент пиров, которые когда-либо успешно проходили проверку в свой день рождения

CREATE OR REPLACE PROCEDURE pd_get_birthdaysuccessful(RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        WITH TotalPeers AS (
            SELECT COUNT(DISTINCT nickname) AS total_peers
            FROM peers
        ),
             BirthdaySuccessful AS (
                 SELECT COUNT(DISTINCT p.nickname) AS successful_peers
                 FROM checks c
                          JOIN peers p ON DATE_PART('day', c.date_) = DATE_PART('day', p.birthday) AND
                                          DATE_PART('month', c.date_) = DATE_PART('month', p.birthday)
                          INNER JOIN verter v ON c.id = v.check_ AND v.state_ = 'Success'
             ),
             BirthdayUnsuccessful AS (
                 SELECT COUNT(DISTINCT p.nickname) AS unsuccessful_peers
                 FROM checks c
                          JOIN peers p ON DATE_PART('day', c.date_) = DATE_PART('day', p.birthday) AND
                                          DATE_PART('month', c.date_) = DATE_PART('month', p.birthday)
                          INNER JOIN verter v ON c.id = v.check_ AND v.state_ = 'Failure'
             )
        SELECT ROUND(successful_peers::numeric / total_peers * 100)   AS SuccessfulChecks,
               ROUND(unsuccessful_peers::numeric / total_peers * 100) AS UnsuccessfulChecks
        FROM TotalPeers,
             BirthdaySuccessful,
             BirthdayUnsuccessful;
END;
$$;

BEGIN;
CALL pd_get_birthdaysuccessful('RESULT');
FETCH ALL IN "RESULT";
END;

-- Task11 Определить всех пиров, которые сдали заданные задания 1 и 2, но не сдали задание 3

CREATE OR REPLACE PROCEDURE pd_find_peers_task1_task2_success_task3_fail(task1 VARCHAR, task2 VARCHAR, task3 VARCHAR, RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        WITH task1_suc AS (
            SELECT DISTINCT peer
            FROM checks
                     INNER JOIN verter v on checks.id = v.check_
            WHERE checks.task = task1
              AND v.state_ = 'Success'
        ),
             task2_suc AS (
                 SELECT DISTINCT peer
                 FROM checks
                          INNER JOIN verter v on checks.id = v.check_
                 WHERE checks.task = task2
                   AND v.state_ = 'Success'
             ),
             task3_fail AS (
                 SELECT DISTINCT peer
                 FROM checks
                          INNER JOIN verter v on checks.id = v.check_
                 WHERE checks.task = task3
                   AND v.state_ = 'Failure'
             )
        SELECT *
        FROM task1_suc
        INTERSECT
        SELECT *
        FROM task2_suc
        INTERSECT
        SELECT *
        FROM task3_fail;
END;
$$;

BEGIN;
CALL pd_find_peers_task1_task2_success_task3_fail('C2_SimpleBashUtils', 'C4_s21_math', 'C7_SmartCalc_v1.0', 'RESULT');
FETCH ALL IN "RESULT";
END;

-- Task12 Используя рекурсивное обобщенное табличное выражение, для каждой задачи вывести кол-во предшествующих ей задач

CREATE OR REPLACE FUNCTION get_prev_count(task_title VARCHAR)
    RETURNS INTEGER
    LANGUAGE SQL
AS $$
    WITH RECURSIVE r AS (
        SELECT
            title,
            0 AS iteration_count
        FROM tasks
        WHERE title = task_title

        UNION ALL

        SELECT t.parenttask,
               r.iteration_count + 1
        FROM tasks t
        JOIN r ON t.title = r.title
    )
    SELECT (MAX(iteration_count) - 1) AS max_iterations
    FROM r
    WHERE title IS NULL;
$$;

CREATE OR REPLACE PROCEDURE pd_get_count_tasks(RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        SELECT title, get_prev_count(title) AS prev_count
        FROM tasks;
END;
$$;

BEGIN;
CALL pd_get_count_tasks('RESULT');
FETCH ALL IN "RESULT";
END;

-- Task13 Найти "удачные" для проверок дни. День считается "удачным", если в нем есть хотя бы N идущих подряд успешных проверки
-- Параметры процедуры: количество идущих подряд успешных проверок N.
-- Временем проверки считать время начала P2P этапа.
-- Под идущими подряд успешными проверками подразумеваются успешные проверки, между которыми нет неуспешных.
-- При этом кол-во опыта за каждую из этих проверок должно быть не меньше 80% от максимального.
-- Формат вывода: список дней

CREATE OR REPLACE FUNCTION count_success_per_day(N INT)
    RETURNS TABLE
            (
                date_        DATE,
                last_counter INT
            )
AS
$$
DECLARE
    cur_date        DATE;
    success_counter INT := 0;
    last_counter    INT := 0;
    check_state     RECORD;
BEGIN
    FOR cur_date IN (
        SELECT DISTINCT checks.date_
        FROM checks
                 JOIN xp x on checks.id = x.check_
                 JOIN tasks t on checks.task = t.title
        WHERE x.xpamount > 0.8 * t.maxxp
        ORDER BY 1
    )
        LOOP
            -- Сброс счетчика перед каждым новым днем
            success_counter := 0;
            last_counter := 0;

            FOR check_state IN (
                SELECT checks.date_, v.state_, v.time_
                FROM checks
                         JOIN verter v on checks.id = v.check_
                WHERE checks.date_ = cur_date
                  AND v.state_ != 'Start'
                ORDER BY 1, 3
            )
                LOOP
                    IF check_state.state_ = 'Failure' THEN
                        success_counter := 0; -- Обнуляем счетчик при встрече значения "Failure"
                    ELSE
                        success_counter := success_counter + 1;
                    END IF;
                    IF last_counter < success_counter THEN
                        last_counter := success_counter;
                    END IF;
                END LOOP;

            -- Возвращаем результаты для текущей даты
--     RETURN QUERY SELECT cur_date, last_counter;
            IF last_counter > N THEN
                RETURN QUERY SELECT cur_date, last_counter;
            END IF;

        END LOOP;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE PROCEDURE pd_get_count_success_per_day(N INT, RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        SELECT * FROM count_success_per_day(N);
END;
$$;

BEGIN;
CALL pd_get_count_success_per_day(0, 'RESULT');
FETCH ALL IN "RESULT";
END;

-- Task14 Определить пира с наибольшим количеством XP

CREATE OR REPLACE PROCEDURE pd_get_max_xp_peer(RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        SELECT peer AS "Peer", SUM(xpamount) AS "XP"
        FROM xp
                 JOIN checks c ON xp.check_ = c.id
        GROUP BY peer
        ORDER BY 2 DESC
        LIMIT 1;
END;
$$;

BEGIN;
CALL pd_get_max_xp_peer('RESULT');
FETCH ALL IN "RESULT";
END;

-- Task15 Определить пиров, приходивших раньше заданного времени не менее N раз за всё время

CREATE OR REPLACE PROCEDURE pd_get_coming_count(N INT, change_time TIME, RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        SELECT peer
        FROM timetracking
        WHERE time_ < change_time
          AND state_ = 1
        GROUP BY peer
        HAVING COUNT(*) > N;
END;
$$;

BEGIN;
CALL pd_get_coming_count(1, '08:30:00', 'RESULT');
FETCH ALL IN "RESULT";
END;

-- Task16 Определить пиров, выходивших за последние N дней из кампуса больше M раз
-- Параметры процедуры: количество дней N, количество раз M.
-- Формат вывода: список пиров

CREATE OR REPLACE PROCEDURE pd_get_left_count(N INT, M INT, RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        SELECT peer
        FROM timetracking
        WHERE date_ > CURRENT_DATE - INTERVAL '1 day' * N
          AND state_ = 2
        GROUP BY peer
        HAVING COUNT(*) > M;
END;
$$;

BEGIN;
CALL pd_get_left_count(10, 1, 'RESULT');
FETCH ALL IN "RESULT";
END;

-- Task17 Определить для каждого месяца процент ранних входов
-- Для каждого месяца посчитать, сколько раз люди, родившиеся в этот месяц, приходили в кампус за всё время (будем называть это общим числом входов).
-- Для каждого месяца посчитать, сколько раз люди, родившиеся в этот месяц, приходили в кампус раньше 12:00 за всё время (будем называть это числом ранних входов).
-- Для каждого месяца посчитать процент ранних входов в кампус относительно общего числа входов.
-- Формат вывода: месяц, процент ранних входов

CREATE OR REPLACE FUNCTION get_percent_early_entries(count_month int)
RETURNS int AS $$
DECLARE
    row_count int;
    all_entries int;
    early_entries int;
BEGIN
    -- all_entries
    SELECT COUNT(*) INTO all_entries
    FROM (
        SELECT nickname
        FROM peers
        JOIN timetracking t ON peers.nickname = t.peer
        WHERE t.state_ = 1 AND EXTRACT(MONTH FROM peers.birthday) = count_month
        AND EXTRACT(MONTH FROM peers.birthday) = EXTRACT(MONTH FROM t.date_)
    ) AS subquery;
    -- early entries
    SELECT COUNT(*) INTO early_entries
    FROM (
        SELECT nickname
        FROM peers
        JOIN timetracking t ON peers.nickname = t.peer
        WHERE t.state_ = 1 AND EXTRACT(MONTH FROM peers.birthday) = count_month
        AND EXTRACT(MONTH FROM peers.birthday) = EXTRACT(MONTH FROM t.date_) AND t.time_ < '12:00:00'
    ) AS subquery;

    IF all_entries = 0 THEN
        row_count := 0;
    ELSE
        row_count :=  early_entries * 100 / all_entries;
    END IF;
    RETURN row_count;
END;
$$ LANGUAGE plpgsql;


CREATE OR REPLACE PROCEDURE pd_get_percent_early_entries(RESULT INOUT REFCURSOR)
    LANGUAGE PLPGSQL AS
$$
BEGIN
    OPEN RESULT FOR
        WITH all_months AS (
            SELECT generate_series(1, 12) AS month_number
        )
        SELECT CASE
                   WHEN all_months.month_number = 1 THEN 'январь'
                   WHEN all_months.month_number = 2 THEN 'февраль'
                   WHEN all_months.month_number = 3 THEN 'март'
                   WHEN all_months.month_number = 4 THEN 'апрель'
                   WHEN all_months.month_number = 5 THEN 'май'
                   WHEN all_months.month_number = 6 THEN 'июнь'
                   WHEN all_months.month_number = 7 THEN 'июль'
                   WHEN all_months.month_number = 8 THEN 'август'
                   WHEN all_months.month_number = 9 THEN 'сентябрь'
                   WHEN all_months.month_number = 10 THEN 'октябрь'
                   WHEN all_months.month_number = 11 THEN 'ноябрь'
                   WHEN all_months.month_number = 12 THEN 'декабрь'
                   ELSE 'неверный месяц'
                   END                                            AS "Month",
               get_percent_early_entries(all_months.month_number) AS "EarlyEntries"
        FROM all_months
        ORDER BY all_months.month_number;
END;
$$;

BEGIN;
CALL pd_get_percent_early_entries('RESULT');
FETCH ALL IN "RESULT";
END;
