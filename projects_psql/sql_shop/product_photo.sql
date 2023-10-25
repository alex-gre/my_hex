create table product_photo(

     id serial primary_key,
     url varchar(255),
     product_id integer references product(id)

);