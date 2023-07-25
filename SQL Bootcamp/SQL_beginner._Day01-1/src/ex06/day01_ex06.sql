SELECT order_date as action_date,
       (SELECT name FROM person WHERE person_order.person_id = person.id) as person_name
FROM person_order
INTERSECT
SELECT visit_date as action_date,
       (SELECT name FROM person WHERE person_visits.person_id = person.id) as person_name
FROM person_visits
ORDER BY action_date, person_name DESC
