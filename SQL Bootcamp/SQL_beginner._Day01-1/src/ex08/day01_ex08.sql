SELECT order_date, concat(name, ' (age:', age, ')') AS person_information
FROM person_order
NATURAL JOIN person AS pc (person_id)
ORDER BY order_date, person_information
