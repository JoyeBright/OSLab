#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
char *msg1 = "Oslab1";
char *msg2 = "Oslab2";
char *msg3 = "Oslab3";
#define PSIZE 20
int main(){
  int pipefd[2];
  int pipe_rv;
  char buf[PSIZE];
  pipe_rv = pipe(pipefd);
  if(pipe_rv<0){
    printf("Pipe Creation has been Failed!");
    exit(-1);
  }
  // Write data into the pipe
  write(pipefd[1],msg1,PSIZE);
  write(pipefd[1],msg2,PSIZE);
  write(pipefd[1],msg3,PSIZE);

  // Read data from the pipe
  for(int i=0;i<3;i++){
    read(pipefd[0],buf,PSIZE);
    printf("%s\n",buf);
  }
  return 0;
}
