create table tcp
( id bigint primary key,
  node1 varchar not null,
  node2 varchar not null,
  cost integer not null
  );

insert into tcp values (1, 'A', 'B', 10);
insert into tcp values (2, 'B', 'A', 10);
insert into tcp values (3, 'A', 'D', 20);
insert into tcp values (4, 'D', 'A', 20);
insert into tcp values (5, 'A', 'C', 15);
insert into tcp values (6, 'C', 'A', 15);
insert into tcp values (7, 'B', 'C', 35);
insert into tcp values (8, 'C', 'B', 35);
insert into tcp values (9, 'D', 'B', 25);
insert into tcp values (10, 'B', 'D', 25);
insert into tcp values (11, 'D', 'C', 30);
insert into tcp values (12, 'C', 'D', 30);

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
        parrent.tour || ',' || child.node1 AS trace,
        child.node1,
        child.node2,
        child.cost,
        parrent.summ + child.cost AS summ
    FROM tcp AS child
    INNER JOIN a_traces AS parrent ON child.node1 = parrent.node2
    WHERE tour NOT LIKE '%' || child.node1 || '%'
)
SELECT summ AS total_cost,
       TRIM(',' FROM tour) AS tour
FROM (
    SELECT tour || ',' || node2 AS tour, summ, RANK() OVER (ORDER BY summ) AS rank_num
    FROM a_traces
    WHERE length(tour) = 7 AND node2 = 'A'
) AS subquery
WHERE rank_num = 1
ORDER BY 1,2;

