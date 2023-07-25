SELECT person.name AS name
FROM person
WHERE EXISTS (
    SELECT 1
    FROM person_order
    WHERE person_order.person_id = person.id
)
ORDER BY person.name ASC;
