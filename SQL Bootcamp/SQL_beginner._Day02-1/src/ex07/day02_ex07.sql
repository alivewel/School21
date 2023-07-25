SELECT pizzeria.name AS pizzeria_name
FROM person_visits
INNER JOIN person_order ON person_order.person_id = person_visits.person_id
INNER JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
INNER JOIN menu ON person_order.menu_id = menu.id
WHERE person_visits.person_id = 9 AND person_visits.visit_date = '2022-01-08'
  AND menu.price <= 800
ORDER BY pizzeria_name