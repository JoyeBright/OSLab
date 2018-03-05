#include <stdio.h>

int main() {
  /* code */
  int i,j,n,bt[20],pos,temp,p[20],wt[20],tat[20];
  float awt=0,atat=0;
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
  //Calculating Waiting Time
  wt[0] = 0;
  for (i = 1; i < n; i++) {
    wt[i] = 0;
    for(j=0;j<i;j++)
      wt[i] = wt[i]+bt[j];
  }
  printf("\nProcess\t Burst Time \t Waiting Time \t TurnAround Time");
  //Calculating TurnAround Time
  for(i=0;i<n;i++)
  {
    tat[i] = bt[i]+wt[i];
    atat = atat+tat[i];
    awt = awt+wt[i];
    printf("\np[%d] \t\t %d \t\t %d \t\t %d",i+1,bt[i],wt[i],tat[i]);
  }
  awt = awt/n;
  atat = atat/n;
  printf("\nAverage Waiting Time:%.2f\n",awt);
  printf("Average TurnAround Time:%.2f\n",atat);

  //...........................................

  return 0;

}
