--- URI Online Judge SQL
--- Copyright URI Online Judge
--- www.urionlinejudge.com.br
--- Problem 2613

CREATE TABLE prices (
  id numeric PRIMARY KEY,
  categorie varchar(50),
  value FLOAT
);


CREATE TABLE movies (
  id numeric PRIMARY KEY,
  name varchar(50),
  id_prices numeric REFERENCES prices (id)
);

INSERT INTO prices (id , categorie, value)
VALUES
  (1,	'Releases',	3.50),
  (2,	'Bronze Seal',	2.00),
  (3,	'Silver Seal',	2.50),
  (4,	'Gold Seal',	3.00),
  (5,	'Promotion',	1.50);
  
INSERT INTO movies (id, name, id_prices)
VALUES
  (1,	'Batman',	3),
  (2,	'The Battle of the Dark River',	3),
  (3,	'White Duck',	5),
  (4,	'Breaking Barriers',	4),
  (5,	'The Two Hours',	2);
  
  /*  Execute this query to drop the tables */
  SELECT movies.id, movies.name FROM movies JOIN prices ON ((prices.id = movies.id_prices) AND (prices.value < 2.00)); 
-- SELECT movies.id, movies.name FROM movies, prices WHERE ((prices.id = movies.id_prices) AND (prices.value < 2.00)); 
-- SELECT movies.id, movies.name FROM movies JOIN prices ON (prices.id = movies.id_prices) WHERE prices.value < 2.00; 

  DROP TABLE movies, prices; --
