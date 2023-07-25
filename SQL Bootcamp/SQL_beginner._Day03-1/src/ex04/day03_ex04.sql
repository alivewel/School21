WITH only_women AS (
    SELECT pizzeria.name AS pizzeria_name
    FROM person_order
    INNER JOIN (SELECT * FROM person WHERE gender = 'male') AS person ON person.id = person_order.person_id
    INNER JOIN menu ON menu.id = person_order.menu_id
    INNER JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
    EXCEPT
    SELECT pizzeria.name AS pizzeria_name
    FROM person_order
    INNER JOIN (SELECT * FROM person WHERE gender = 'female') AS person ON person.id = person_order.person_id
    INNER JOIN menu ON menu.id = person_order.menu_id
    INNER JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
), only_men AS (
    SELECT pizzeria.name AS pizzeria_name
    FROM person_order
    INNER JOIN (SELECT * FROM person WHERE gender = 'female') AS person ON person.id = person_order.person_id
    INNER JOIN menu ON menu.id = person_order.menu_id
    INNER JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
    EXCEPT
    SELECT pizzeria.name AS pizzeria_name
    FROM person_order
    INNER JOIN (SELECT * FROM person WHERE gender = 'male') AS person ON person.id = person_order.person_id
    INNER JOIN menu ON menu.id = person_order.menu_id
    INNER JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
)
SELECT pizzeria_name
FROM only_men
UNION
SELECT pizzeria_name
FROM only_women
ORDER BY 1;
