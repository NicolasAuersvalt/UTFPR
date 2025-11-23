SELECT STRAIGHT_JOIN
    n.n_name,
    SUM(l.l_extendedprice * (1 - l.l_discount)) AS revenue
FROM
    ORDERS o
    JOIN LINEITEM l      ON l.l_orderkey = o.o_orderkey
    JOIN CUSTOMER c      ON c.c_custkey = o.o_custkey
    JOIN SUPPLIER s      ON l.l_suppkey = s.s_suppkey
    JOIN NATION n        ON s.s_nationkey = n.n_nationkey
    JOIN REGION r        ON n.n_regionkey = r.r_regionkey
WHERE
    r.r_name = 'MIDDLE EAST'
    AND o.o_orderdate >= DATE('1994-01-01')
    AND o.o_orderdate < DATE('1994-01-01') + INTERVAL 1 YEAR
GROUP BY
    n.n_name
ORDER BY
    revenue DESC;