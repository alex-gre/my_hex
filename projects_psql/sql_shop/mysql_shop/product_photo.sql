create table product_photo(

     id integer primary key auto_increment,
     url varchar(255),
     product_id integer references product(id)

);