#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSGSIZE 30

char* msg1 = "Hello, OSLab962-1";
char* msg2 = "Hello, OSLab962-2";
char* msg3 = "Hello, OSLab962-3";

int main(){

  int pipefd[2],nbytes;
  pid_t pid;
  char inbuf[MSGSIZE];

  if(pipe(pipefd)<0)
   exit(1);
   
  if((pid = fork())>0){
    write(pipefd[1], msg1, MSGSIZE);
    write(pipefd[1], msg2, MSGSIZE);
    write(pipefd[1], msg3, MSGSIZE);
    // close(pipefd[1]) wont hang on
    close(pipefd[1]);
    //............................
  }else{
    // close(pipefd[1]) wont hang on
    close(pipefd[1]);
    //.............................
    while((nbytes = read(pipefd[0], inbuf, MSGSIZE))>0){
          printf("%s\n", inbuf);
          printf("The number of bytes actually read is: %d\n", nbytes);
    }
    if(nbytes!=0)
      exit(2);
    printf("\n***Finished Reading***\n");
  }
  return 0;
}
