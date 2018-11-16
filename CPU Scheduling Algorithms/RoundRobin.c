#include <stdio.h>
#include <stdlib.h>


int main(){
  int n, burst[30], wt[30], tat[30], remain[30],quantum;
  int time=0;
  int flag = 0; //to show finished process
  float awt=0, atat=0;

  printf("Enter Total Number of Processes:");
  scanf("%d",&n);
  int rp = n; // number of remained processes
  printf("Enter Time Quantum:");
  scanf("%d",&quantum);

  printf("Enter the Burst Times:\n");
  for (int i = 0; i < n; i++) {
    printf("Burst Time P[%d]:",i+1);
    scanf("%d",&burst[i]);
    remain[i]= burst[i];

  }

  while(1){ // we do this until there is no unfinished process
    for (int i = 0 ; i < n; i++){
      if(remain[i]<=quantum && remain[i]>0){
        time+= remain[i]; // total time until now
        wt[i]=time - burst[i];// the total time that has passed minus the burst time of process
        remain[i]=0; // the process is finished
        flag=1;

        printf("P%d\n",i+1);
      }
      if(remain[i]>quantum){
        remain[i]-= quantum;
        time += quantum;
        printf("P%d\n",i+1);
      }
      if(remain[i]==0 && flag==1)
        rp--; // update the number of remained processes
        flag=0;
    }
    if(rp==0){ // there is no unfinished process
      break;

    }


  }
  printf("\nProcess\t\t Burst Time \t\t Waiting Time \t\t TurnAround Time \n");
  for (int i = 0; i < n; i++) {
    tat[i]=wt[i]+burst[i]; // calculating the TurnAround time
    atat += tat[i];
    awt += wt[i];
    printf("\nP[%d] \t\t\t %d \t\t\t %d \t\t\t %d \n",i+1,burst[i],wt[i],tat[i]);
  }
printf("\n");
printf("Average Turnaround Time is %.2f\n", (float)atat/n);
printf("Average Waiting Time is %.2f\n", (float)awt/n);


}
