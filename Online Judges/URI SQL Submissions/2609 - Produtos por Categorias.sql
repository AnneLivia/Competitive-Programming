-- URI Online Judge SQL
-- Copyright URI Online Judge
-- www.urionlinejudge.com.br
-- Problem 2609

CREATE TABLE categories (
  id numeric PRIMARY KEY,
  name varchar(100)
);

CREATE TABLE products (
  id numeric PRIMARY KEY,
  name varchar(50),
  amount numeric,
  price numeric(7,2),
  id_categories numeric REFERENCES categories (id)
);

INSERT INTO categories (id, name)
VALUES 
  (1,	'wood'),
  (2,	'luxury'),
  (3,	'vintage'),
  (4,	'modern'),
  (5,	'super luxury');
  
INSERT INTO products (id, name, amount, price, id_categories)
VALUES 
  (1,	'Two-doors wardrobe', 100,	800,	1),
  (2,	'Dining table',	1000,	560,	3),
  (3,	'Towel holder',	10000,	25.50,	4),
  (4,	'Computer desk',	350,	320.50,	2),
  (5,	'Chair',	3000,	210.64,	4),
  (6,	'Single bed',	750,	460,	1);
  
 select ca.name, sum(po.amount) as sum 
 FROM categories as ca 
 INNER JOIN products as 
 po on ca.id = po.id_categories group by ca.name;
 
  DROP TABLE categories,products; --