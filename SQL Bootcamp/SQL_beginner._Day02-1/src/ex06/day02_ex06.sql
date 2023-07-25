SELECT menu.pizza_name AS pizza_name, pizzeria.name AS pizzeria_name
FROM person_order
INNER JOIN menu ON menu.id = person_order.menu_id
INNER JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
WHERE person_order.person_id = 4 OR person_order.person_id = 1
ORDER BY pizza_name, pizzeria_name