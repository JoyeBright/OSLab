#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main() {
  /* code */
  // take one argument status and returns
  // a process ID of dead children.
  // pid_t wait(int *stat_loc);
  pid_t cpid;
  if(fork()==0)
    exit(0);
  else
     cpid = wait(NULL);
  printf("Parent pid = %d\n",getpid());
  printf("Child pid = %d\n",cpid );

  return 0;

}
