CREATE TABLE account (
	id numeric PRIMARY KEY,
    name varchar(255),
    login varchar(255),
    password varchar(255)
);

INSERT INTO account (
	id,
    name,
    login,
    password
) VALUES 
	(1, 'Joyce P. Parry', 'Promeraw', 'noh1Oozei'),
	(2, 'Michael T. Gonzalez', 'Phers1942', 'Iath3see9bi'),
	(3, 'Heather W. Lawless', 'Hankicht', 'diShono4'),
	(4, 'Otis C. Hitt', 'Conalothe', 'zooFohH7w'),
	(5, 'Roger N. Brownfield', 'Worseente', 'fah7ohNg');

SELECT id, password, md5(password) AS MD5 FROM account;
    
DROP TABLE account;

