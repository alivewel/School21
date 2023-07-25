CREATE UNIQUE INDEX idx_menu_unique ON menu (pizzeria_id, pizza_name);

SET enable_seqscan = OFF;

EXPLAIN ANALYZE
SELECT pizzeria_id, pizza_name
FROM menu
JOIN pizzeria ON menu.pizzeria_id = pizzeria.id;

