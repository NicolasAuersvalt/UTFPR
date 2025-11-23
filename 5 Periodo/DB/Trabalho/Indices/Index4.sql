CREATE INDEX idx_l_q4_exists ON LINEITEM (l_orderkey, l_commitdate, l_receiptdate);


CREATE INDEX idx_o_q4_cover ON ORDERS (o_orderdate, o_orderpriority);