SELECT DISTINCT pizzeria.name AS pizzeria_name
FROM person_order
INNER JOIN  person_visits ON person_order.person_id = person_order.person_id
INNER JOIN (SELECT * FROM person WHERE name = 'Andrey') AS person ON person.id = person_visits.person_id
INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
INNER JOIN (SELECT * FROM menu WHERE id = 8 OR id = 9) AS menu ON person_order.menu_id = menu.id
WHERE person_order.person_id = 2 AND pizzeria.id = 1
ORDER BY 1;
