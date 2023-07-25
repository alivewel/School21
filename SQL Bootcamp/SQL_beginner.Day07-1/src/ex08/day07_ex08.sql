SELECT person.address AS address,
       pizzeria.name AS name,
       COUNT(*) AS count_of_orders
FROM person
JOIN person_order on person.id = person_order.person_id
JOIN menu ON person_order.menu_id = menu.id
JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
GROUP BY address, pizzeria.name
ORDER BY 1, 2;