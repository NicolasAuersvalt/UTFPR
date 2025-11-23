-- Otimização para Q3 e Q5 (ORDERS )
CREATE INDEX idx_orders_date
ON ORDERS (O_ORDERDATE);

-- otimização para Q3 ( CUSTOMER )
CREATE INDEX idx_customer_mkt
ON CUSTOMER (C_MKTSEGMENT);

-- otimização para Q6 ( LINEITEM )
CREATE INDEX idx_lineitem_q6
ON LINEITEM (L_SHIPDATE, L_DISCOUNT , L_QUANTITY);