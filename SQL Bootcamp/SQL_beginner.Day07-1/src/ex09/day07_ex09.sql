SELECT  person.address AS address,
        ROUND((MAX(age) - (CAST(MIN(age) AS DECIMAL) / MAX(age))), 2) AS formula,
        ROUND(AVG(age), 2) AS average,
        CASE
           WHEN (ROUND((MAX(age) - (CAST(MIN(age) AS DECIMAL) / MAX(age))), 2) > ROUND(AVG(age), 2)) THEN 'true'
            ELSE 'false'
        END AS comparison
FROM person
GROUP BY address
ORDER BY 1;