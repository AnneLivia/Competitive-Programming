## CREATE SCHEMA `juridicas`;

/*
	Problem struction from URI in portuguese:
		O setor de vendas quer fazer uma promoção para todos os clientes que são pessoas jurídicas. 
        Para isso você deve exibir o nome dos clientes que sejam pessoa jurídica.
*/

# creating table of customers
CREATE TABLE customers (
	id numeric PRIMARY KEY,
    name char varying (255),
    street char varying (255),
    city char varying (255),
    state char(2),
    credit_limit numeric
);

# creating table of legal_person that connects with the customers id
CREATE TABLE legal_person (
	id_customers NUMERIC,
    FOREIGN KEY(id_customers) REFERENCES customers(id),
    cnpj char varying (18),
    contact char varying(255)
);

# insert values into the table
INSERT INTO customers (
	id,
    name,
    street,
    city,
    state,
    credit_limit
) VALUES 
	(1,	'Nicolas Diogo Cardoso',	'Acesso Um',	'Porto Alegre',	'RS',	475),
	(2,	'Cecília Olivia Rodrigues',	'Rua Sizuka Usuy',	'Cianorte',	'PR',	3170),
	(3,	'Augusto Fernando Carlos Eduardo Cardoso',	'Rua Baldomiro Koerich',	'Palhoça',	'SC',	1067),
	(4,	'Nicolas Diogo Cardoso',	'Acesso Um',	'Porto Alegre',	'RS',	475),
	(5,	'Sabrina Heloisa Gabriela Barros',	'Rua Engenheiro Tito Marques Fernandes',	'Porto Alegre',	'RS',	4312),
	(6,	'Joaquim Diego Lorenzo Araújo',	'Rua Vitorino',	'Novo Hamburgo',	'RS',	2314);

# insert values into the table
INSERT INTO legal_person (
	id_customers,
    cnpj,
    contact
) VALUES 
	(4,	'85883842000191',	'99767-0562'),
	(5,	'47773848000117',	'99100-8965');

SELECT name 
FROM customers 
INNER JOIN legal_person ON customers.id = legal_person.id_customers;

/*
	TO SELECT DATA FROM MULTIPLE TABLES:
	INNER JOIN: Only see rows where there are matching records in A and B.
    RIGHT JOIN: All rows in B and only matchings in A
    LEFT JOIN: All rows in A and only matchings in B
    FULL JOIN: All rows in A and B
*/

