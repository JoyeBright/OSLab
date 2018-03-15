#include <stdio.h>
#include <stdlib.h>

int main()
{
  int HeadCurrentPosition,MaxTrackNum,ElementNum;
  printf("Enter the currect head position:");
  scanf("%d",&HeadCurrentPosition);
  printf("\nEnter the Maximum tracks number:");
  scanf("%d",&MaxTrackNum);
  printf("\nEnter number of the tracks that we are seeking:");
  scanf("%d",&ElementNum);

  printf("\nEnter the tracks number in order:\n");

  int count1=0,count2=0,queue[ElementNum],seektime=0,TotalSeekTime=0;
  while (count1<ElementNum)
  {
    int value;
    scanf("%d",&value);
    if(value>0 && value<=MaxTrackNum) queue[count1]=value;
    count1++;
  }

  while (count2<ElementNum) {

    seektime = abs(HeadCurrentPosition-queue[count2]);
    printf("%d--(%d)-->%d\n",HeadCurrentPosition,seektime,queue[count2]);
    HeadCurrentPosition = queue[count2];
    TotalSeekTime +=seektime;
    count2++;
  }

  printf("The Total seek time is equal to:%.2f\n",(float)TotalSeekTime);
  printf("The Average of total seek time is equal to:%.2f\n",(float)TotalSeekTime/ElementNum);

  return 0;

}
