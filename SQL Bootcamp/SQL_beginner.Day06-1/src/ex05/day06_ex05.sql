COMMENT ON TABLE person_discounts IS 'table that shows the size of the discount for a person and a pizzeria';
COMMENT ON COLUMN person_discounts.id IS 'serial number for table row';
COMMENT ON COLUMN person_discounts.person_id IS 'serial number for a person';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'serial number for a pizzeria';
COMMENT ON COLUMN person_discounts.discount IS 'percentage discount per person';

-- просмотр комментариев ко всей таблице
-- SELECT obj_description('person_discounts'::regclass) AS table_comment;

-- просмотр комментариев по столбцам
-- SELECT a.attname AS column_name, col_description(a.attrelid, a.attnum) AS column_comment
-- FROM pg_attribute a
-- WHERE a.attrelid = 'person_discounts'::regclass
-- AND a.attnum > 0;