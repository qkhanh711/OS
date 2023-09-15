#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
void main(){
   int pid;
   pid=fork();
   if(pid<0) {
      printf("cannot create the process");
      exit(-1);
   }
   if(pid==0) {
      printf("\n Child Process\n");
      printf("\n Child Process id is %d ",getpid());
      printf("\n Its parent process id is %d",getppid());
      sleep(5);
      printf("\n Child process after sleep=5");
      printf("\n Child Process id is %d ",getpid());
      printf("\n Its parent process id is %d\n\n",getppid());
      exit(0);
   }
   else {
      printf("\n Parent process");
      sleep(10);
      printf("\n Child Process id is %d ",getpid());
      printf("\n Its parent process id is %d",getppid());
      printf("\n Parent terminates\n");
   }
}