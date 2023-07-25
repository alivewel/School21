SELECT menu.pizza_name, pizzeria.name AS pizzeria_name, menu.price
FROM pizzeria
LEFT JOIN menu ON menu.pizzeria_id = pizzeria.id
WHERE menu.pizza_name = 'pepperoni pizza' OR menu.pizza_name = 'mushroom pizza'
ORDER BY menu.pizza_name, pizzeria_name