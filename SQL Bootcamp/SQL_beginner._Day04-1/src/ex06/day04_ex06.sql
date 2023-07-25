CREATE VIEW mv_dmitriy_visits_and_eats AS
SELECT pizzeria.name AS pizzeria_name
FROM person_visits
INNER JOIN person ON person.id = person_visits.person_id
INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
INNER JOIN menu ON menu.pizzeria_id = person_visits.pizzeria_id
WHERE person_visits.person_id = 9 AND person_visits.visit_date = '2022-01-08'
  AND menu.price < 800
ORDER BY pizzeria_name;

-- SELECT *
-- FROM mv_dmitriy_visits_and_eats
-- ORDER BY 1;

