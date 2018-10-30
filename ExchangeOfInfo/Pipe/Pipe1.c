// Pipe behave Like FIFO (Queue DS)
// Size of Read and Write dont match with each other
// Can write 512 Bytes at a time but can read only 1 Byte at a time in Pipe

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>

#define MSGSIZE 20

char *msg1 = "Hello, OSLab962-1";
char *msg2 = "Hello, OSLab962-2";
char *msg3 = "Hello, OSLab962-3";

int main() {
  char inbuf[MSGSIZE];
  int pipefd[2];
  if(pipe(pipefd)<0)// we can use perror()
   exit(1);

  write(pipefd[1],msg1,MSGSIZE);
  write(pipefd[1],msg2,MSGSIZE);
  write(pipefd[1],msg2,MSGSIZE);

  for(int i=0;i<3;i++){
    // Read pipe
    read(pipefd[0],inbuf, MSGSIZE);
    printf("%s\n",inbuf);
  }
  // Suppress -Wno-write-strings to gcc

  return 0;
}
