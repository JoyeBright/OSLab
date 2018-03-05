#include <stdio.h>

int main() {
  /* code */
  int i,j,n,bt[20],pos,temp,p[20];
  printf("Enter Total Number of Processes:");
  scanf("%d",&n);

  printf("Enter the following Burst Times:\n");
  for (i = 0; i < n; i++) {
    /* code */
    printf("Burst Time P[%d]:",i+1);
    scanf("%d",&bt[i]);

  }
  //Sorting burst time in ascending order...
  //Selection Sort..........................
  for(i=0;i<n;i++)
  {
    pos = i;
    for(j=i+1;j<n;j++)
    {
      if(bt[j]<bt[pos])
         pos = j;
    }
    //substitute
    temp = bt[i];
    bt[i] = bt[pos];
    bt[pos] = temp;

    temp = p[i];
    p[i] = p[pos];
    p[pos] = temp;
  }

  //...........................................
  return 0;

}
