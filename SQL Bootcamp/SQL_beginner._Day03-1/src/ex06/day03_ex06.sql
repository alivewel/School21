SELECT p1.pizza_name AS pizza_name,
       (SELECT pizzeria.name FROM pizzeria WHERE p2.pizzeria_id = pizzeria.id) as pizzeria_name_1,
       (SELECT pizzeria.name FROM pizzeria WHERE p1.pizzeria_id = pizzeria.id) as pizzeria_name_2,
       p1.price AS price
FROM menu p1
INNER JOIN menu p2 ON p1.pizza_name = p2.pizza_name AND p1.price = p2.price
INNER JOIN pizzeria ON p1.pizzeria_id = pizzeria.id
WHERE p1.pizzeria_id < p2.pizzeria_id
ORDER BY p1.pizza_name;