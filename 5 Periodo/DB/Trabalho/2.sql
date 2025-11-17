SELECT
    s_acctbal,
    s_name,
    n_name,
    p_partkey,
    p_mfgr,
    s_address,
    s_phone,
    s_comment
FROM
    PART p
    JOIN PARTSUPP ps   ON p.p_partkey = ps.ps_partkey
    JOIN SUPPLIER s    ON s.s_suppkey = ps.ps_suppkey
    JOIN NATION n      ON s.s_nationkey = n.n_nationkey
    JOIN REGION r      ON n.n_regionkey = r.r_regionkey
WHERE
    p.p_size = 30
    AND p.p_type LIKE '%STEEL'
    AND r.r_name = 'ASIA'
    AND ps.ps_supplycost = (
        SELECT MIN(ps2.ps_supplycost)
        FROM PARTSUPP ps2
             JOIN SUPPLIER s2 ON s2.s_suppkey = ps2.ps_suppkey
             JOIN NATION n2   ON s2.s_nationkey = n2.n_nationkey
             JOIN REGION r2   ON n2.n_regionkey = r2.r_regionkey
        WHERE
            ps2.ps_partkey = p.p_partkey
            AND r2.r_name = 'ASIA'
    )
ORDER BY
    s_acctbal DESC,
    n_name,
    s_name,
    p_partkey
LIMIT 100;

