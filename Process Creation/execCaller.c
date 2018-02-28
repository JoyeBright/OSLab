#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  /* code */
  char *args[] = {"./exec.out",NULL} ;
  execvp(args[0],args);
        /*All statements are ignored after execvp() call as this whole
        process(execCaller.c) is replaced by another process (exec.c)
        */
        printf("I am the message after 'execvp'!!");
  return 0;
}
