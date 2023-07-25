SELECT person.name AS name,
       menu.pizza_name AS pizza_name,
       menu.price AS price,
       ROUND(price - (price * person_discounts.discount / 100)) AS discount_price,
       pizzeria.name AS pizzeria_name
FROM person_order
JOIN menu ON menu.id = person_order.menu_id
JOIN person ON person_order.person_id = person.id
JOIN person_discounts ON person.id = person_discounts.person_id
    AND person_discounts.pizzeria_id = menu.pizzeria_id
JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
WHERE person_order.id IS NOT NULL
ORDER BY 1, 2;
