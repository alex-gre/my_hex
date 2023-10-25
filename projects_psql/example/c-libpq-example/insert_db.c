#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libpq-fe.h>



void insertData(PGconn *conn, int id, char name[45],int price) {
    char query[256];
    sprintf(query, "INSERT INTO cars (id,name, price) VALUES (%d,'%s',%d);",id, name ,price);
    PGresult *result = PQexec(conn, query);
    if (result) {
        PQclear(result);
    } else {
        fprintf(stderr, "Error while executing query: %s\n", query);
    }
}

int main(void) {

   PGconn *conn = PQconnectdb("user=alex password=qwerty dbname=mydb");

   int id;
   char name[45];
   int price;


    printf("Input id > ");
	scanf("%d",&id);
	printf("Input name > ");
	scanf("%s",name);
	printf("Input price > ");
	scanf("%d",&price);
	 
    insertData(conn, id, name, price);

    return 0;


}