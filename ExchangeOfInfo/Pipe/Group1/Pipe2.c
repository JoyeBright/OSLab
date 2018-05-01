#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char *msg1 = "OSLabl962-1";
char *msg2 = "OSLabl962-2";
char *msg3 = "OSLabl962-3";

#define PSIZE 20

int main(){
 int pipefd[2],nbyte;
 pid_t pid;
 char buf[PSIZE];
 pipe(pipefd);
 if(pipe<0){
   printf("Pipe Creation has been Failed");
   exit(-1);
 }
 pid = fork();
 if(pid>0){
   //Parent Process
   write(pipefd[1],msg1,PSIZE);
   write(pipefd[1],msg2,PSIZE);
   write(pipefd[1],msg3,PSIZE);
   //.........................
   close(pipefd[1]);
   //.........................
   wait(NULL);
 }else{
   //Child Process
   close(pipefd[1]);
   while((nbyte = read(pipefd[0],buf,PSIZE))>0){
        printf("%s\n",buf);
   }
   printf("Reading has been finished!\n");
 }

}
