WITH missing_dates AS (
SELECT generate_series('2022-01-01'::date, '2022-01-10'::date, '1 day') AS missing_date
)
SELECT TO_CHAR(missing_dates.missing_date, 'YYYY-MM-DD') AS missing_date
FROM missing_dates
LEFT JOIN person_visits ON missing_dates.missing_date = person_visits.visit_date
AND (person_visits.person_id = 1 OR person_visits.person_id = 2)
WHERE person_visits.visit_date IS NULL
ORDER BY missing_dates.missing_date;