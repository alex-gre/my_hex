PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE customer (
    id integer primary key autoincrement ,
    name varchar(255),
    phone varchar(30),
    email varchar(255)
    );
INSERT INTO customer VALUES(1,'alex','212222','al@mail');
INSERT INTO customer VALUES(2,'user2','212222','us2@mail');
INSERT INTO customer VALUES(3,'user3','2132','us3@mail');
CREATE TABLE product(

   id integer  primary key autoincrement,
   name varchar(255),
   description text,
   price integer
   
   );
CREATE TABLE product_photo(

     id integer primary key autoincrement,
     url varchar(255),
     product_id integer references product(id)

);
DELETE FROM sqlite_sequence;
INSERT INTO sqlite_sequence VALUES('customer',3);
COMMIT;
