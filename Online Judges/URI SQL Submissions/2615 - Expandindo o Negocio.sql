## CREATE SCHEMA negocio;

CREATE TABLE customers (
	id NUMERIC PRIMARY KEY,
    name CHAR VARYING(255),
    street CHAR VARYING(255),
    city CHAR VARYING(255)
);

INSERT INTO customers (
	id,
    name,
    street,
    city
) VALUES
	(1,	'Giovanna Goncalves Oliveira',	'Rua Mato Grosso',	'Canoas'),
	(2, 'KauÃ£ Azevedo Ribeiro',	'Travessa Ibiá','Uberlândia'),
	(3,	'Rebeca Barbosa Santos',	'Rua Observatório Meteorológico',	'Salvador'),
	(4,	'Sarah Carvalho Correia',	'Rua Antônio Carlos da Silva',	'Uberlândia'),
	(5,	'JoÃ£o Almeida Lima',	'Rua Rio Taiuva',	'Ponta Grossa'),
	(6,	'Diogo Melo Dias',	'Rua Duzentos e Cinquenta',	'Varzea Grande');
    
SELECT DISTINCT city FROM customers;

DROP TABLE customers;
