SELECT person.name
FROM person_order
INNER JOIN person ON person.id = person_order.person_id
INNER JOIN menu ON menu.id = person_order.menu_id
WHERE (menu.pizza_name = 'cheese pizza')
   AND person.gender = 'female'
INTERSECT
SELECT person.name
FROM person_order
INNER JOIN person ON person.id = person_order.person_id
INNER JOIN menu ON menu.id = person_order.menu_id
WHERE menu.pizza_name = 'pepperoni pizza'
   AND person.gender = 'female'
ORDER BY 1


