CREATE VIEW v_price_with_discount AS
SELECT person.name AS person_name,
       menu.pizza_name,
       menu.price,
       ROUND(menu.price - menu.price * 0.1)::integer AS discount_price
FROM person_order
JOIN person ON person.id = person_order.person_id
JOIN menu ON menu.id = person_order.menu_id
ORDER BY 1, 2;

-- SELECT *
-- FROM v_price_with_discount
-- ORDER BY 1, 2;
--
-- DROP VIEW v_price_with_discount;