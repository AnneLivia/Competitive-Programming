--- URI Online Judge SQL
--- Copyright URI Online Judge
--- www.urionlinejudge.com.br
--- Problem 2611

CREATE TABLE genres (
  id numeric PRIMARY KEY,
  description varchar(50)
);

CREATE TABLE movies (
  id numeric PRIMARY KEY,
  name varchar(50),
  id_genres numeric REFERENCES genres (id)
);

INSERT INTO genres (id, description)
VALUES
  (1,	'Animation'),
  (2,	'Horror'),
  (3,	'Action'),
  (4,	'Drama'),
  (5,	'Comedy');
  
INSERT INTO movies (id, name, id_genres)
VALUES
  (1,	'Batman',	3),
  (2,	'The Battle of the Dark River',	3),
  (3,	'White Duck',	1),
  (4,	'Breaking Barriers',	4),
  (5,	'The Two Hours',	2);

/*  Execute this query to drop the tables */
select mo.id, mo.name FROM movies as mo
inner join genres as ge on (mo.id_genres = ge.id AND ge.description = 'Action');
DROP TABLE movies, genres; --

