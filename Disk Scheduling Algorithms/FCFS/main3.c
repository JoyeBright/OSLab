#include <stdio.h>
#include <stdlib.h>

int main()
{
  int CurrentHead,MaxTrackNum,ElementNum;

  printf("Enter the current number of the cylinder\n");
  scanf("%d",&CurrentHead);
  printf("Enter the maximum track number\n");
  scanf("%d",&MaxTrackNum);
  printf("Enter the number of the tracks\n");
  scanf("%d",&ElementNum);

  printf("Please Enter the request in order\n");

  int count1=0,count2=0,queue[ElementNum],seekTime=0,TotalSeekTime=0;
  while(count1<ElementNum)
  {
    int value;
    scanf("%d",&value);

    if(value>0 && value<=MaxTrackNum)
    {
      queue[count1] = value;
    }

    count1++;
  }
  while(count2<ElementNum)
  {
    seekTime = abs(CurrentHead - queue[count2]);
    printf("%d---(%d)-->%d\n",CurrentHead,seekTime,queue[count2] );
    CurrentHead = queue[count2];
    count2++;
    TotalSeekTime +=seekTime;
  }

  printf("The total Seek time is equal to:%d\n",TotalSeekTime);
  printf("The average of total seek time is equal to:%.2f",(float)TotalSeekTime/ElementNum);

  // for (int i = 0; i < ElementNum; i++) {
  //   printf("%d\n",queue[i]);
  // }

}
