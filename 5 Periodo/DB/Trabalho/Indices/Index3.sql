CREATE INDEX idx_c_mktsegment ON CUSTOMER (c_mktsegment);

-- Primeiro, remova o índice que deixou lento
DROP INDEX idx_c_mktsegment ON CUSTOMER;

-- Crie este novo índice COMPOSTO (Segmento + Chave Primária)
CREATE INDEX idx_c_cover ON CUSTOMER (c_mktsegment, c_custkey);



-- Índice composto para o JOIN e o filtro de DATA ao mesmo tempo
CREATE INDEX idx_o_join_date ON ORDERS (o_custkey, o_orderdate);