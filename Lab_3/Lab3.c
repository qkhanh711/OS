#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
   int id;
   id=fork();
   if(id<0) {
      printf("cannot create the process");
      exit(-1);
   }
   if(id==0) {
      sleep(10);
      printf("child process \n");
      exit(0);
   }
   else {
      printf("parent process \n");
   }
}  