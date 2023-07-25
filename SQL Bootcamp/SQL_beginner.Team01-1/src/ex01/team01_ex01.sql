SELECT
    COALESCE(u.name, 'not defined') AS name,
    COALESCE(u.lastname, 'not defined') AS lastname,
    c.name AS currency_name,
    (money * rate_to_usd) AS currency_in_usd
FROM balance b
LEFT JOIN "user" u on b.user_id = u.id
JOIN currency c ON c.id = b.currency_id
WHERE c.updated = (
    SELECT CASE
        WHEN b.updated < (SELECT MIN(updated) FROM currency WHERE id = b.currency_id) THEN
            (SELECT MIN(updated) FROM currency WHERE id = b.currency_id AND b.updated < updated)
        ELSE
            (SELECT MAX(updated) FROM currency WHERE id = b.currency_id AND b.updated > updated)
        END
    )
ORDER BY name DESC, lastname, currency_name;
