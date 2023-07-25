CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date
(pperson VARCHAR DEFAULT 'Dmitriy', pprice numeric DEFAULT 500,
pdate date DEFAULT '2022-01-08')
RETURNS TABLE (pizzeria_name VARCHAR) AS
$$
BEGIN
    RETURN QUERY
    SELECT DISTINCT pizzeria.name
    FROM person_order
    JOIN menu ON menu.id = person_order.menu_id
    JOIN pizzeria ON menu.pizzeria_id = pizzeria.id
    JOIN person ON person_order.person_id = person.id
    JOIN person_visits ON person_visits.person_id = person.id
        AND person_visits.visit_date = person_order.order_date
    WHERE person_order.order_date = pdate
        AND person.name = pperson
        AND menu.price < pprice;
END;
$$ LANGUAGE plpgsql;

SELECT *
FROM fnc_person_visits_and_eats_on_date(pprice := 800);

SELECT *
FROM fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');

--
-- SELECT *
-- FROM fnc_person_visits_and_eats_on_date(pperson := 'Denis', pprice := 2000, pdate := '2022-01-07');