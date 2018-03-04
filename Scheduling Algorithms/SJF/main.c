#include <stdio.h>

int main() {
  /* code */
  int i,n,bt[20];
  printf("Enter Total Number of Processes:");
  scanf("%d",&n);

  printf("Enter Burst Time:\n");
  for (i = 0; i < n; i++) {
    /* code */
    printf("Burst Time P[%d]:",i+1);
    scanf("%d",&bt[i]);
  }
  return 0;

}
