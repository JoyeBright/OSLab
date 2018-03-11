#include <stdio.h>
#include <stdlib.h>

struct track
{
   int trackId;
   struct track *nextTrack;

};

void clearScreen()
{
  printf("\033[H\033[J");
}

void FCFS()
{
  int maxTrack,trackNum,tempStore;
  struct track  *pointer = NULL;
  struct track  *startPointer = NULL;
  clearScreen();
  printf("FCFS Simulation:\n\n");
  printf("Enter the total number of tracks available in the disk\n");
  scanf("%d",&maxTrack);
  printf("Enter number of tracks that you would like to seek\n");
  scanf("%d",&trackNum);
  printf("\nEnter the track Ids in order:\n");

  int i=0;
  while(i<trackNum)
  {
    scanf("%d",&tempStore);
    if(tempStore>0 && tempStore<=maxTrack)
    {
      if(pointer!=NULL)
      {
        pointer = (track*)malloc(sizeof(struct track));
        pointer = pointer->nextTrack;
      }
      else
      {
        pointer = (track*)malloc(sizeof(struct track));
        startPointer = pointer;
      }
      pointer->trackId = tempStore;
      pointer->nextTrack = NULL;
      i++;

    }
    else
    {
      printf("Invalid TrackId inputted,input again.\n");
    }
  }

}
int main()
{
  FCFS();
}
