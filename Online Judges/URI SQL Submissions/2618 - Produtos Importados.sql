--- URI Online Judge SQL
--- Copyright URI Online Judge
--- www.urionlinejudge.com.br
--- Problem 2618

CREATE TABLE providers (
  id numeric PRIMARY KEY,
  name varchar(255),
  street varchar(255),
  city varchar(255),
  state char(2)
);

CREATE TABLE categories (
  id numeric PRIMARY KEY,
  name varchar(255)
);

CREATE TABLE products (
  id numeric PRIMARY KEY,
  name varchar (255),
  amount numeric,
  price numeric,
  id_providers numeric REFERENCES providers (id),
  id_categories numeric REFERENCES categories (id)
);

INSERT INTO providers (id, name, street, city, state)
VALUES
  (1,	'Ajax SA',	'Rua Presidente Castelo Branco',	'Porto Alegre',	'RS'),
  (2,	'Sansul SA',	'Av Brasil',	'Rio de Janeiro',	'RJ'),
  (3,	'South Chairs',	'Rua do Moinho',	'Santa Maria',	'RS'),
  (4,	'Elon Electro',	'Rua Apolo',	'SÃ£o Paulo',	'SP'),
  (5,	'Mike Electro',	'Rua Pedro da Cunha',	'Curitiba',	'PR');

INSERT INTO categories (id, name)
VALUES
  (1,	'Super Luxury'),
  (2,	'Imported'),
  (3,	'Tech'),
  (4,	'Vintage'),
  (5,	'Supreme');
  
INSERT INTO products (id, name, amount, price, id_providers, id_categories)
VALUES
  (1,	'Blue Chair',	30,	300.00,	5,	5),
  (2,	'Red Chair',	50,	2150.00,	2,	1),
  (3,	'Disney Wardrobe',	400,	829.50,	4,	1),
  (4,	'Blue Toaster',	20,	9.90,	3,	1),
  (5,	'TV',	30,	3000.25,	2,	2);
  
SELECT prod.name, prov.name, cate.name FROM products prod
INNER JOIN categories cate ON prod.id_categories = cate.id 
INNER JOIN providers prov ON prov.id = prod.id_providers
WHERE prov.name = 'Sansul SA' AND cate.name = 'Imported'; 


/*  Execute this query to drop the tables */
DROP TABLE products, categories, providers; --