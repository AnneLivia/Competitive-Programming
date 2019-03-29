CREATE TABLE virus (
  id INTEGER,
  name VARCHAR(255)
);


INSERT INTO virus(
	id, 
    name
) VALUES 
      (1, 'H1RT'),
      (2, 'H7H1'),
      (3, 'HUN8'),
      (4, 'XH1HX'),
      (5, 'XXXX');

SELECT REPLACE(name, 'H1', 'X') FROM virus;
  
DROP TABLE virus; --
