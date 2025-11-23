--- PARA CRIAR

CREATE INDEX idx_fix_q5_orders 
ON ORDERS (o_orderdate, o_orderkey, o_custkey);

CREATE INDEX idx_fix_q5_lineitem 
ON LINEITEM (l_orderkey, l_suppkey, l_extendedprice, l_discount);

--- PARA DELETAR

DROP INDEX idx_fix_q5_orders ON LINEITEM;

DROP INDEX idx_fix_q5_lineitem ON LINEITEM;


id|select_type|table|type  |possible_keys                                                              |key         |key_len|ref               |rows  |Extra                                          |
--+-----------+-----+------+---------------------------------------------------------------------------+------------+-------+------------------+------+-----------------------------------------------+
 1|SIMPLE     |c    |index |PRIMARY                                                                    |CUSTOMER_FK1|4      |                  |148828|Using index; Using temporary; Using filesort   |
 1|SIMPLE     |o    |ref   |PRIMARY,ORDERS_FK1,idx_orders_date,idx_orders_q5_covering,idx_fix_q5_orders|ORDERS_FK1  |4      |tpch.c.C_CUSTKEY  |7     |Using where                                    |
 1|SIMPLE     |l    |ref   |PRIMARY                                                                    |PRIMARY     |4      |tpch.o.O_ORDERKEY |2     |                                               |
 1|SIMPLE     |s    |eq_ref|PRIMARY,SUPPLIER_FK1                                                       |PRIMARY     |4      |tpch.l.L_SUPPKEY  |1     |                                               |
 1|SIMPLE     |n    |eq_ref|PRIMARY,NATION_FK1                                                         |PRIMARY     |4      |tpch.s.S_NATIONKEY|1     |                                               |
 1|SIMPLE     |r    |ALL   |PRIMARY                                                                    |            |       |                  |5     |Using where; Using join buffer (flat, BNL join)|



 SHOW INDEX FROM LINEITEM;
