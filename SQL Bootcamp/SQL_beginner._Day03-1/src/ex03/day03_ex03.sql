WITH only_women AS (
    SELECT pizzeria.name AS pizzeria_name
    FROM person_visits
    INNER JOIN (SELECT * FROM person WHERE gender = 'female') AS person ON person.id = person_visits.person_id
    INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
    EXCEPT ALL
    SELECT pizzeria.name AS pizzeria_name
    FROM person_visits
    INNER JOIN (SELECT * FROM person WHERE gender = 'male') AS person ON person.id = person_visits.person_id
    INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
), only_men AS (
    SELECT pizzeria.name AS pizzeria_name
    FROM person_visits
    INNER JOIN (SELECT * FROM person WHERE gender = 'male') AS person ON person.id = person_visits.person_id
    INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
    EXCEPT ALL
    SELECT pizzeria.name AS pizzeria_name
    FROM person_visits
    INNER JOIN (SELECT * FROM person WHERE gender = 'female') AS person ON person.id = person_visits.person_id
    INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
)
SELECT pizzeria_name
FROM only_women
UNION ALL
SELECT pizzeria_name
FROM only_men
ORDER BY 1;
