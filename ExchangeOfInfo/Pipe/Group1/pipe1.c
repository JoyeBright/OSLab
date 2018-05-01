#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *msg1 = "OSlab962-1";
char *msg2 = "OSLab962-2";
char *msg3 = "OSLab962-3";
#define PSIZE 20
int main(){
  int pipefd[2];
  int pipe_rv;
  char buf[20];
  pipe_rv = pipe(pipefd);
  if(pipe_rv<0){
    perror("Pipe Creation Failed");
    exit(-1);
  }
  //Write into the pipe
  write(pipefd[1],msg1,PSIZE);
  write(pipefd[1],msg2,PSIZE);
  write(pipefd[1],msg3,PSIZE);

  //Read Data from pipe

  for(int i=0;i<3;i++){
     read(pipefd[0],buf,PSIZE);
     printf("%s\n",buf);
  }

  return 0;
}
