INSERT INTO person_visits (id, person_id, pizzeria_id, visit_date)
VALUES (
    (SELECT MAX(id) + 1 FROM person_visits),
    (SELECT id FROM person WHERE name = 'Dmitriy'),
    (SELECT id FROM pizzeria WHERE name = 'Best Pizza'),
    '2022-01-08'
);

REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;

-- SELECT pizzeria.name AS pizzeria_name,
--        menu.price,
--        person_visits.visit_date AS visit_date,
--        person_visits.pizzeria_id AS pizzeria_id
--
-- FROM person_visits
-- INNER JOIN person ON person.id = person_visits.person_id
-- INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
-- INNER JOIN menu ON menu.pizzeria_id = person_visits.pizzeria_id
-- WHERE person_visits.person_id = 9
--   AND person_visits.visit_date = '2022-01-08'
--   AND menu.price < 800
-- ORDER BY pizzeria_name;
--
-- DELETE FROM person_visits
-- WHERE id = 20;
--
-- SELECT *
-- FROM mv_dmitriy_visits_and_eats
-- ORDER BY 1;

