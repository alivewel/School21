CREATE VIEW v_generated_dates AS
SELECT generate_series('2022-01-01'::date, '2022-01-31'::date, '1 day')::date AS generated_date
ORDER BY 1;


-- SELECT TO_CHAR(generated_date, 'YYYY-MM-DD') AS generated_date
-- FROM v_generated_dates
-- ORDER BY 1;
--
-- DROP VIEW v_generated_dates;