INSERT INTO person_order (id, person_id, menu_id, order_date)
SELECT
    (SELECT COALESCE(MAX(id), 0) + gs.person_id FROM person_order),
    gs.person_id,
    (SELECT id FROM menu WHERE pizza_name = 'greek pizza'),
    '2022-02-25'
FROM generate_series(1, 10) AS gs(person_id)
WHERE gs.person_id IN (SELECT id FROM person);
