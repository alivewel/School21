SELECT person.name
FROM person_order
INNER JOIN person ON person.id = person_order.person_id
INNER JOIN menu ON menu.id = person_order.menu_id
WHERE (person.address = 'Moscow' OR person.address = 'Samara')
   AND (menu.pizza_name = 'pepperoni pizza' OR menu.pizza_name = 'mushroom pizza')
   AND person.gender = 'male'
ORDER BY person.name DESC