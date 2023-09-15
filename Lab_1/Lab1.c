#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main (){
   int id;
   id=fork();
   sleep(10);
   if(id<0) {
      printf("cannot create the file");
      exit(-1);
   }
   if(id==0) {
      printf("child process \n");
      exit(0);
   }
   else {
      printf("parent process \n");
   }
   return 0;
}