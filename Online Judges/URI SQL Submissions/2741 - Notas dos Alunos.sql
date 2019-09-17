--- URI Online Judge SQL
--- Copyright URI Online Judge
--- www.urionlinejudge.com.br
--- Problem 2741

CREATE TABLE students(
  id INTEGER PRIMARY KEY,
  name VARCHAR(255),
  grade numeric(3,1)
);


INSERT INTO students(id, name, grade)
VALUES (1, 'Terry B. Padilla',7.3),
       (2, 'William S. Ray',0.6),
       (3, 'Barbara A. Gongora',5.2),
       (4, 'Julie B. Manzer', 6.7),
       (5, 'Teresa J. Axtell', 4.6),
       (6, 'Ben M. Dantzler', 9.6);

  SELECT concat('Approved: ', students.name) AS name, grade FROM students WHERE grade >= 7.0 ORDER BY grade DESC; 
  /*  Execute this query to drop the tables */
  DROP TABLE students; --
