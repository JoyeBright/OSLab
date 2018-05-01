#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *msg1 = "Hello-OSlab962-1";
char *msg2 = "Hello-OSlab962-2";
char *msg3 = "Hello-OSlab962-3";
#define PSIZE 20
int main(){
  int pipefd[2];
  int pipe_id;
  pipe_id = pipe(pipefd);
  char buf[PSIZE];
  // Error Handeling
  if(pipe_id<0){
    perror("Pipe return -1 value which shows an error!");
    exit(-1);
  }
  //Write sth into the pipe
  write(pipefd[1],msg1,PSIZE);
  write(pipefd[1],msg2,PSIZE);
  write(pipefd[1],msg3,PSIZE);

  // Read data from the pipe
  for(int i=0;i<3;i++){
    read(pipefd[0],buf,PSIZE);
    printf("%s\n",buf);
  }


}
