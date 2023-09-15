#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main (){
   int id,i;
   id=fork();
   sleep(10);
   if(id<0) {
      printf("Cannot create the file");
      exit(-1);
   }
   if(id==0) {
      printf("Child process \n");
      for (i=0;i<10;i++)

      {
          printf("Dong %d\n",i);
          sleep(1);
      }
      exit(10);
   }
   else {
      printf("Parent process \n");
      for (i=100;i<110;i++)
      {
          printf("Dong %d\n",i);
          sleep(1);
      }
   }
   exit(0);
}