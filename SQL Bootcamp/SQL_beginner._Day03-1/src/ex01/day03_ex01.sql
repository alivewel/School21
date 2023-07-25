SELECT id AS menu_id
FROM menu
LEFT JOIN (SELECT DISTINCT menu_id FROM person_order) AS person_order ON person_order.menu_id = menu.id
WHERE person_order.menu_id IS NULL
ORDER BY 1;