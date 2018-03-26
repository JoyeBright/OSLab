#include <stdio.h>
#include <stdlib.h>

int main()
{
   int CurrentHeadNum,MaxTrackNum,ElementNum;
   printf("Enter the current number of the header\n");
   scanf("%d",&CurrentHeadNum);
   printf("Enter the maximum number of the tracks\n");
   scanf("%d",&MaxTrackNum);
   printf("Enter the the element/request number\n");
   scanf("%d",&ElementNum);

   printf("Enter the requests in order\n");
   int count1=0,count2=0,queue[ElementNum],SeekTime=0,TotalSeekTime=0;
   while (count1<ElementNum) {
      int value;
      scanf("%d",&value);
      if(value>0 && value<=MaxTrackNum)
      {
          queue[count1] = value;
      }
      count1++;
   }
   while (count2<ElementNum) {
     SeekTime = abs(CurrentHeadNum - queue[count2]);
     printf("%d----(%d)---->%d\n",CurrentHeadNum,SeekTime,queue[count2]);
     CurrentHeadNum = queue[count2];
     TotalSeekTime +=SeekTime;
     count2++;
   }

   printf("The Total seek time is equal to:%d\n",TotalSeekTime);
   printf("The Average Total seek time is equal to:%.2f\n",(float)TotalSeekTime/ElementNum);

   // for (int i = 0; i < ElementNum; i++) {
   //   printf("%d\n",queue[i]);
   // }
}
