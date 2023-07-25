DROP TABLE IF EXISTS
   Peers, Tasks, P2P, Verter, Checks, TransferredPoints, Friends, Recommendations, XP, TimeTracking;


DROP TYPE IF EXISTS CheckStatus CASCADE;

CREATE TABLE Peers
(
    Nickname VARCHAR(255) PRIMARY KEY NOT NULL,-- Ник пира
    Birthday DATE                     NOT NULL -- День рождения
);

CREATE TABLE Tasks
(
    Title      VARCHAR(255) PRIMARY KEY NOT NULL, -- Название задания
    ParentTask VARCHAR(255),                      -- Название задания, являющегося условием входа
    MaxXP      INT                      NOT NULL, -- Максимальное количество XP
    CHECK (MaxXP >= 0),
    CONSTRAINT FK_TASKS_TASKS_TITLE FOREIGN KEY (ParentTask) REFERENCES Tasks (Title)
);


CREATE TYPE CheckStatus AS ENUM ('Start', 'Success', 'Failure');

CREATE TABLE Checks
(
    ID    SERIAL PRIMARY KEY,    -- ID
    Peer  VARCHAR(255) NOT NULL, -- Ник пира
    Task  VARCHAR(255) NOT NULL, -- Название задания
    Date_ DATE         NOT NULL, -- Дата проверки
    FOREIGN KEY (Task) REFERENCES Tasks (Title),
    FOREIGN KEY (Peer) REFERENCES Peers (Nickname),
    CONSTRAINT unique_check UNIQUE (Peer, Task)
);

CREATE TABLE P2P
(
    ID           SERIAL PRIMARY KEY,    -- ID
    Check_       INT          NOT NULL, -- ID проверки
    CheckingPeer VARCHAR(255) NOT NULL, -- Ник проверяющего пира
    State_       CheckStatus  NOT NULL, -- Статус P2P проверки
    Time_        TIME         NOT NULL, -- Время
    FOREIGN KEY (Check_) REFERENCES Checks (ID),
    FOREIGN KEY (CheckingPeer) REFERENCES Peers (Nickname),
    CONSTRAINT unique_p2p UNIQUE (check_, State_)
);

CREATE TABLE Verter
(
    ID     SERIAL PRIMARY KEY,   -- ID
    Check_ INT         NOT NULL, -- ID проверки
    State_ CheckStatus NOT NULL, -- Статус проверки Verter'ом
    Time_  TIME        NOT NULL, -- Время
    FOREIGN KEY (Check_) REFERENCES Checks (ID),
    CONSTRAINT unique_verter UNIQUE (check_, State_)
);


CREATE TABLE TransferredPoints
(
    ID           SERIAL PRIMARY KEY,    -- ID
    CheckingPeer VARCHAR(255) NOT NULL, -- Ник проверяющего пира
    CheckedPeer  VARCHAR(255) NOT NULL, -- Ник проверяемого пира
    PointsAmount INT,                   -- Количество переданных пир поинтов за всё время (только от проверяемого к проверяющему)
    FOREIGN KEY (CheckingPeer) REFERENCES Peers (Nickname),
    FOREIGN KEY (CheckedPeer) REFERENCES Peers (Nickname),
    CONSTRAINT unique_transferredpoints UNIQUE (CheckingPeer, CheckedPeer)
);

CREATE TABLE Friends
(
    ID    SERIAL PRIMARY KEY,    -- ID
    Peer1 VARCHAR(255) NOT NULL, -- Ник первого пира
    Peer2 VARCHAR(255) NOT NULL, -- Ник второго пира
    FOREIGN KEY (Peer1) REFERENCES Peers (Nickname),
    CHECK (Peer1 != Peer2),
    FOREIGN KEY (Peer2) REFERENCES Peers (Nickname),
    CONSTRAINT unique_friends UNIQUE (Peer1, Peer2)
);

CREATE TABLE Recommendations
(
    ID              SERIAL PRIMARY KEY,    -- ID
    Peer            VARCHAR(255) NOT NULL, -- Ник пира
    RecommendedPeer VARCHAR(255) NOT NULL, -- Ник пира, к которому рекомендуют идти на проверку
    FOREIGN KEY (Peer) REFERENCES Peers (Nickname),
    CHECK (Peer != RecommendedPeer),
    FOREIGN KEY (RecommendedPeer) REFERENCES Peers (Nickname),
    CONSTRAINT unique_recommendations UNIQUE (Peer, RecommendedPeer)
);

CREATE TABLE XP
(
    ID       SERIAL PRIMARY KEY, -- ID
    Check_   INT NOT NULL,       -- ID проверки
    XPAmount INT NOT NULL,       -- Количество полученного XP
    FOREIGN KEY (Check_) REFERENCES Checks (ID),
    CHECK (XPAmount >= 0),
    CONSTRAINT unique_xp UNIQUE (Check_)
);


CREATE TABLE TimeTracking
(
    ID     SERIAL PRIMARY KEY,    -- ID
    Peer   VARCHAR(255) NOT NULL, -- Ник пира
    Date_  DATE         NOT NULL, -- Дата
    Time_  TIME         NOT NULL, -- Время
    State_ INT          NOT NULL, -- Состояние (1 - пришел, 2 - вышел)
    FOREIGN KEY (Peer) REFERENCES Peers (Nickname),
    CHECK (State_ IN (1, 2))
);

-- example for working with procedure
-- https://proglib.io/p/funkcii-i-hranimye-procedury-v-sql-zachem-nuzhny-i-kak-primenyat-v-realnyh-primerah-2022-10-07

CREATE OR REPLACE FUNCTION fnc_check_status_verter_on_insert()
RETURNS TRIGGER AS $$
BEGIN
    IF (NEW.State_ = 'Success' OR NEW.State_ = 'Failure') THEN
        IF NOT EXISTS (
            SELECT 1 FROM Verter v
            WHERE v.Check_ = NEW.Check_ AND v.State_ = 'Start'
        ) THEN
            RAISE EXCEPTION 'Cannot add Success or Failure without Start for the same Check';
        END IF;
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_check_status_verter_on_insert
BEFORE INSERT OR UPDATE ON Verter
FOR EACH ROW
EXECUTE FUNCTION fnc_check_status_verter_on_insert();

CREATE OR REPLACE FUNCTION fnc_verter_count_checks_limit()
RETURNS TRIGGER AS $$
DECLARE
    verter_count INTEGER;
BEGIN
    SELECT COUNT(*) INTO verter_count FROM Verter WHERE Check_ = NEW.Check_;
    IF verter_count >= 2 THEN
        RAISE EXCEPTION 'Cannot add more than 2 records with the same Check';
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_verter_count_checks_limit
BEFORE INSERT OR UPDATE ON Verter
FOR EACH ROW
EXECUTE FUNCTION fnc_verter_count_checks_limit();

-- INSERT INTO VERTER VALUES ((SELECT MAX(id) + 1 FROM VERTER), 4, 'Start', '09:33:33');
-- INSERT INTO VERTER VALUES ((SELECT MAX(id) + 1 FROM VERTER), 4, 'Success', '09:33:33');
-- INSERT INTO VERTER VALUES ((SELECT MAX(id) + 1 FROM VERTER), 4, 'Failure', '09:33:33');
-- INSERT INTO Verter (Check_, State_, Time_) VALUES (4, 'Start', '09:33:33');


CREATE OR REPLACE FUNCTION fnc_check_status_p2p_on_insert()
RETURNS TRIGGER AS $$
BEGIN
    IF (NEW.State_ = 'Success' OR NEW.State_ = 'Failure') THEN
        IF NOT EXISTS (
            SELECT 1 FROM P2P v
            WHERE v.Check_ = NEW.Check_ AND v.State_ = 'Start'
        ) THEN
            RAISE EXCEPTION 'Cannot add Success or Failure without Start for the same Check';
        END IF;
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_check_status_p2p_on_insert
BEFORE INSERT OR UPDATE ON P2P
FOR EACH ROW
EXECUTE FUNCTION fnc_check_status_p2p_on_insert();


CREATE OR REPLACE FUNCTION fnc_p2p_count_checks_limit()
RETURNS TRIGGER AS $$
DECLARE
    p2p_count INTEGER;
BEGIN
    SELECT COUNT(*) INTO p2p_count FROM P2P WHERE Check_ = NEW.Check_;
    IF p2p_count >= 2 THEN
        RAISE EXCEPTION 'Cannot add more than 2 records with the same Check';
    END IF;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_p2p_count_checks_limit
BEFORE INSERT OR UPDATE ON P2P
FOR EACH ROW
EXECUTE FUNCTION fnc_p2p_count_checks_limit();

-- INSERT INTO P2P VALUES ( (SELECT MAX(id) + 1 FROM P2P), 4, 'lopata', 'Start', '09:33:33');
-- INSERT INTO P2P VALUES ( (SELECT MAX(id) + 1 FROM P2P), 4, 'lopata', 'Success', '09:33:33');
-- INSERT INTO P2P VALUES ( (SELECT MAX(id) + 1 FROM P2P), 4, 'lopata', 'Failure', '09:33:33');




CREATE OR REPLACE PROCEDURE import_csv(table_name TEXT, file_path TEXT)
    LANGUAGE plpgsql
AS
$$
BEGIN
    EXECUTE format('COPY %I FROM %L DELIMITER %L CSV', table_name, file_path, ',');
END;
$$;

CREATE OR REPLACE PROCEDURE export_csv(table_name TEXT, file_path TEXT)
    LANGUAGE plpgsql
AS
$$
BEGIN
    EXECUTE format('COPY %I TO %L DELIMITER %L CSV', table_name, file_path, ',');
END;
$$;


-- '/Users/marlinto/Desktop/SQL2_Info21_v1.0-3/src/csv/peers_import.csv'

--peers
CALL import_csv('peers', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/peers_import.csv');
--tasks
CALL import_csv('tasks', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/tasks_import.csv');
--checks
CALL import_csv('checks', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/checks_import.csv');
--p2p
CALL import_csv('p2p', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/p2p_import.csv');
--verter
CALL import_csv('verter', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/verter_import.csv');
--transferredpoints
CALL import_csv('transferredpoints', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/transferredpoints_import.csv');
--xp
CALL import_csv('xp', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/xp_import.csv');
--timetracking
CALL import_csv('timetracking', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/timetracking_import.csv');
--friends
CALL import_csv('friends', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/friends_import.csv');
--recommendations
CALL import_csv('recommendations', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/recommendations_import.csv');




--peers
CALL export_csv('peers', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/peers_export.csv');
--tasks
CALL export_csv('tasks', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/tasks_export.csv');
--checks
CALL export_csv('checks', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/checks_export.csv');
--p2p
CALL export_csv('p2p', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/p2p_export.csv');
--verter
CALL export_csv('verter', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/verter_export.csv');
--transferredpoints
CALL export_csv('transferredpoints',
                '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/transferredpoints_export.csv');
--xp
CALL export_csv('xp', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/xp_export.csv');
--timetracking
CALL export_csv('timetracking', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/timetracking_export.csv');
--friends
CALL export_csv('friends', '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/friends_export.csv');
--recommendations
CALL export_csv('recommendations',
                '/Users/alivewel/SQL2_Info21_v1.0-3/src/csv/recommendations_export.csv');




