SELECT
    o_orderpriority,
    COUNT(*) AS order_count
FROM
    ORDERS o
WHERE
    o.o_orderdate >= DATE('1995-01-01')
    AND o.o_orderdate < DATE('1995-01-01') + INTERVAL 3 MONTH
    AND EXISTS (
        SELECT 1
        FROM LINEITEM l
        WHERE l.l_orderkey = o.o_orderkey
          AND l.l_commitdate < l.l_receiptdate
    )
GROUP BY
    o_orderpriority
ORDER BY
    o_orderpriority;

