#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#define PSIZE 16

char *msg1 = "Oslab962-1";
char *msg2 = "Oslab962-2";
char *msg3 = "Oslab962-3";

int main(){
  int pipe_rv;
  int pipefd[2];
  char buf[PSIZE];
  int nbytes;
  pipe_rv = pipe(pipefd);
  if(pipe_rv<0){
    perror("Pipe Creation Failed!");
    exit(-1);
  }
  int pid;
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
  }
  else{
    //Child Process
    close(pipefd[1]);
    while((nbytes = read(pipefd[0],buf,PSIZE))>0){
        printf("%s\n",buf);
    }
    printf("Reading From the pipe has been finished!\n");
  }
  return 0;
}
