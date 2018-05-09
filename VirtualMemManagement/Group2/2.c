#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

const int TLB_SIZE = 16;
const int VM_SIZE = 256;
int main(int argc, char const *argv[]) {
  /* code */
  int tlb[TLB_SIZE][2];
  int virtual_memory[VM_SIZE][2];
  //initialization for TLB
  for(int i=0;i<TLB_SIZE;i++){
    tlb[i][0]= (i > TLB_SIZE -1)? -1 : i;
    tlb[i][1]= (i > TLB_SIZE -1)? -1 : TLB_SIZE-i;
  }
  //error handling
  if(argc!=2){
    printf("Error in number of arguments!\n");
    return 1;
  }
  int pageFaultCount = 0;
  printf("Virtual address translation\n");
  printf("---------------------------\n");

  FILE *fp;
  fp = fopen(argv[1],"r");
  if(fp == NULL){
    printf("There is a problem in openning the file %s : %s!",argv[1],strerror(errno));
    return 1;
  }
  ssize_t read;
  char *line = NULL;
  size_t len = 0;
  while((read = getline(&line, &len, fp) )!= -1){
   int offset = atoi(line) & 255;
   int page = atoi(line) & 62280;
   int pageNumber = page >> 8;
   printf("Page#:%d\n",pageNumber);
   int tlb_hit = 0;
   for(int i=0;i<TLB_SIZE;i++){
     if(tlb[i][0]==pageNumber){
       tlb_hit=1;
       printf("TLB HIT\n");
       break;
     }
   }
   if(!tlb_hit){
     pageFaultCount++;
   }

  }

  printf("Page fault number:%d\n",pageFaultCount);

  return 0;
}
