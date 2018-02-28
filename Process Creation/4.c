#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  /* code */
  int p = fork();
  if(p>0)
  {
    fork();
    printf("OSLab962\n");
  }
  printf("OSLab962\n");
  return 0;
}
