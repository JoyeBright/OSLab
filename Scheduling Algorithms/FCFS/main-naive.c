#include <stdio.h>

int main()
{
  int n,i,j,bt[20],wt[20],tat[20];
  float awt,atat,tbt=0,twt=0,ttat=0;
  printf("\nPlease enter total number of Processes:");
  scanf("%d",&n);

  printf("\nPlease Enter the burst values: \n");
  for(i=0;i<n;i++)
  {
      printf("Burst value for P[%d]= ",i+1);
      scanf("%d",&bt[i]);
      tbt=tbt+bt[i]; //It is not needed
  }
//Calculating Waiting Time.................................
  wt[0]=0;
  for(i=1;i<n;i++)
  {
    for(j=0;j<i;j++)
    {
      wt[i]=bt[j]+wt[j];
    }
    twt = twt+wt[i];
  }
  twt +=wt[0];

//Calculating Turnaround Time.................................
  tat[0] = bt[0];
  for(i=1;i<n;i++)
  {
    for(j=0;j<i;j++)
    {
      tat[i] = tat[j]+bt[i];
    }
    ttat = ttat + tat[i];
  }
  ttat += tat[0];

//Display the output.................................
 printf("\nProcess\t\t Burst Time \t\t Waiting Time \t\t TurnAround Time ");
 for(i=0;i<n;i++)
  printf("\nP[%d] \t\t\t %d \t\t\t %d \t\t\t %d",i+1,bt[i],wt[i],tat[i]);

//Calculting AWT and ATAT.................................
  awt = twt/n;
  atat = ttat/n;
  printf("\nAverage Waitng Time: %.2f",awt );
  printf("\nAverage TurnAround Time: %.2f \n",atat );

 return 0;
}
