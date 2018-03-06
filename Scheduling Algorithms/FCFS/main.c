#include <stdio.h>

int main() {

  int n,i,j,bt[20],wt[20],tat[20];
  float awt=0,atat=0;

  printf("\nPlease Enter Total number of the processes: \n");
  scanf("%d",&n);

  for(i=0;i<n;i++) //Assign Burst times to the different processes
  {

    printf("\nEnter Burst Time for P[%d] :",i+1);
    scanf("%d",&bt[i]);
  }

//Calculating Waiting Time---------------------------
//Process1 = wt[0]
//Process2 = wt[1]
    int k = 0; //Remember the sum of previous burst times
    tat[0] = bt[0];
    wt[0] = 0;
    for(i=0;i<n;i++)
    {
      k += bt[i-1];
      wt[i] = k;
      //Calculating TurnAround Time
      tat[i] = k + bt[i];
    }

  printf("\nProcess\t\t Burst Time \t\t Waiting Time \t\t TurnAround Time ");

//Calculating TurnAround Time----------------------------
    for (i=0;i<n;i++)
    {
      //tat[i] = bt[i]+wt[i];
      //Calculated in previous loop
      awt = awt+wt[i];
      atat = atat+tat[i];
      printf("\nP[%d] \t\t\t %d \t\t\t %d \t\t\t %d",i+1,bt[i],wt[i],tat[i]);
    }

  awt = awt/i;
  atat = atat /i;
  printf("\n\nAverage Waitng Time: %.2f",awt );
  printf("\nAverage TurnAround Time: %.2f \n",atat );
  //-------------------------------------------------------

  return 0;
}
