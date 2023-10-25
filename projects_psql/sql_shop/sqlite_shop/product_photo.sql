create table product_photo(

     id integer primary key autoincrement,
     url varchar(255),
     product_id integer references product(id)

);