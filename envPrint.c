#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv[],char *env[]){

int i;
i=0;
printf("======================================================================\n");
printf("|                                                                     |\n");
while(env[i]){
    printf("%d:%s\n",i,env[i]);
    i++;
  }
  printf("======================================================================\n");
  getch();
  return 0;
}

