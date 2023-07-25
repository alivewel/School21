WITH R AS (
    SELECT person_id
    FROM person_visits
    WHERE visit_date = '2022-01-02'
    EXCEPT
    SELECT person_id
    FROM person_visits
    WHERE visit_date = '2022-01-06'
), S AS (
    SELECT person_id
    FROM person_visits
    WHERE visit_date = '2022-01-06'
    EXCEPT
    SELECT person_id
    FROM person_visits
    WHERE visit_date = '2022-01-02'
)
SELECT *
FROM R
UNION
SELECT *
FROM S
ORDER BY 1;
