CREATE INDEX idx_l_q6_revenue ON LINEITEM (
    l_shipdate,      -- Filtro principal (Range de 1 ano)
    l_discount,      -- Filtro secundário (Between)
    l_quantity,      -- Filtro terciário (< 24)
    l_extendedprice  -- Apenas para o cálculo (SUM)
);