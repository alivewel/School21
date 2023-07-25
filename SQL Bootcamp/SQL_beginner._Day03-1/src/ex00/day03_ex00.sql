SELECT DISTINCT menu.pizza_name AS pizza_name,
       menu.price AS price,
       pizzeria.name AS pizzeria_name,
       person_visits.visit_date AS visit_date
FROM menu
INNER JOIN (SELECT * FROM person_visits WHERE visit_date = '2022-01-03' OR visit_date = '2022-01-04') AS person_visits ON person_visits.pizzeria_id = menu.pizzeria_id
INNER JOIN (SELECT * FROM person WHERE name = 'Kate') AS person ON person.id = person_visits.person_id
INNER JOIN person_order ON person_order.person_id = person_visits.person_id
INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
WHERE menu.price BETWEEN 800 AND 1000
ORDER BY 1,2,3;
