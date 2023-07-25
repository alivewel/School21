SELECT person.name AS name, COUNT(*) AS count_of_visits
FROM person_visits
JOIN person ON person.id = person_visits.person_id
GROUP BY person.name
HAVING COUNT(*) > 3
ORDER BY count_of_visits DESC, person.name ASC;