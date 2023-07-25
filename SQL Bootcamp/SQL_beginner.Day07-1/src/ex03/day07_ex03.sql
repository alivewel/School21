WITH orders AS (
    SELECT pizzeria.name AS pizzeria_name,
       COUNT(*) AS count,
       'order' AS action_type
    FROM person_order
    JOIN menu ON menu.id = person_order.menu_id
    JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
    GROUP BY pizzeria.name
    ORDER BY count DESC, pizzeria.name ASC
), visits AS (
    SELECT pizzeria.name AS pizzeria_name,
       COUNT(*) AS count,
       'visit' AS action_type
    FROM person_visits
    JOIN pizzeria ON pizzeria.id = person_visits.pizzeria_id
    GROUP BY pizzeria.name
    ORDER BY count DESC, pizzeria.name ASC
), sum AS (SELECT orders.pizzeria_name, (orders.count + visits.count) AS total_count
    FROM orders
    JOIN visits ON orders.pizzeria_name = visits.pizzeria_name)
SELECT pizzeria.name,
       COALESCE(sum.total_count, '0') AS total_count
FROM pizzeria
FULL JOIN sum ON pizzeria.name = sum.pizzeria_name
ORDER BY 2 DESC, 1 ASC;