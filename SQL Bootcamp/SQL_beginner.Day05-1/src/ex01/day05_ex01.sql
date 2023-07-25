SET enable_seqscan = OFF;

EXPLAIN ANALYZE
SELECT menu.pizza_name AS pizza_name,
       pizzeria.name AS pizzeria_name
FROM menu
INNER JOIN pizzeria ON pizzeria.id = menu.pizzeria_id;
