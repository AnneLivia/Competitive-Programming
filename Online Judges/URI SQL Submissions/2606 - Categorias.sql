--- URI Online Judge SQL
--- Problem 2606

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
  (1,	'old stock'),
  (2,	'new stock'),
  (3,	'modern'),
  (4,	'commercial'),
  (5,	'recyclable'),
  (6,	'executive'),
  (7,	'superior'),
  (8,	'wood'),
  (9,	'super luxury'),
  (10,	'vintage');
  
INSERT INTO products (id , name, amount, price, id_categories)
VALUES
  (1,	'Lampshade',	100,	800,	4),
  (2,	'Table for painting',	1000,	560,	9),
  (3,	'Notebook desk',	10000,	25.50,	9),
  (4,	'Computer desk',	350,	320.50,	6),
  (5,	'Chair',	'3000',	'210.64',	9),	
  (6,	'Home alarm',	750,	460,	4);
  
  SELECT p.id, p.name FROM products as p, 
  categories as c WHERE p.id_categories = c.id 
  AND c.name LIKE ('%super%');

  DROP TABLE products, categories; 