(SELECT TO_CHAR(generated_date, 'YYYY-MM-DD') AS missing_date
FROM v_generated_dates
ORDER BY 1)
EXCEPT
(SELECT DISTINCT TO_CHAR(visit_date, 'YYYY-MM-DD') AS missing_date
FROM person_visits
ORDER BY 1)
ORDER BY 1;