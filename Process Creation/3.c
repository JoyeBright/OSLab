#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  /* code */
  fork();
  fork();
  fork();
  printf("OSLab962\n");
  return 0;
  // So what does it conclude?
  // Number of Times OSLab962 printed is equal to number of process created
  // Total Number of Process = 2^n where n is number of fork system calls
  
}
