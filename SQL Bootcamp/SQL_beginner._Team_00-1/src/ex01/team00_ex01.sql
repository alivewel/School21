WITH RECURSIVE a_traces AS (
    SELECT
        node1 AS tour,
        node1,
        node2,
        cost,
        cost AS summ
    FROM tcp
    WHERE node1 = 'A'
    UNION ALL
    SELECT
        parrent.tour || ',' || child.node1  AS trace ,
        child.node1,
        child.node2,
        child.cost,
        parrent.summ + child.cost AS summ
    FROM tcp AS child
    INNER JOIN a_traces AS parrent ON child.node1 = parrent.node2
    WHERE tour NOT LIKE '%' || child.node1 || '%'
)
SELECT summ AS total_cost,
       tour || ',' || node2 AS tour
FROM a_traces
WHERE length(tour) = 7 AND node2 = 'A'
ORDER BY 1,2;