#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

const int TLB_SIZE = 16;
const int PAGE_SIZE = 256;
const int VM_SIZE = 256;
const int MM_SIZE = 128;
const int FRAME_SIZE = 256;

int main(int argc, char const *argv[]) {
  /* code */
  int tlb[TLB_SIZE][2];
  int virtual_memory[VM_SIZE][2]; // After finding Page number, we fetch frame number
  int physical_mem[MM_SIZE];

  //Initialization for TLB
  for(int i=0; i<TLB_SIZE; i++) {
    tlb[i][0] = (i > TLB_SIZE - 1)? -1 : i;
    tlb[i][1] = (i > TLB_SIZE - 1)? -1 : TLB_SIZE-i;
  }
  //Initialization for Page table
  for (int i=0; i<VM_SIZE;i++){
    virtual_memory[i][0] = (i > MM_SIZE - 1)? -1 : i;
    virtual_memory[i][1] = (i > MM_SIZE - 1)? -1 : MM_SIZE - i;
  }
  //Initialization for Physical Memory
  for(int i=0;i<MM_SIZE;i++){
    physical_mem[i] = i;
  }
  //Error handling for file entry
  if(argc!=2){
    printf("Wrong number of entry arguments\n");
    return 1;
  }

  FILE *fp;
  fp = fopen(argv[1], "r");
  //Check to be sure which the file is not empty and there is no problem
  if(fp == NULL){
    printf("Error opening file %s : %s\n",argv[1],strerror(errno));
    return 1;
  }
  int pageFaultCount = 0;
  int physicalAddress = 0;

   printf("*******************************\n");
   printf(".. Virtual Memory Manager    ..\n");
   printf("*******************************\n");

   printf("Translating Logical Addresses to Physical Addresses\n\n");

   char *line = NULL;
   ssize_t read;
   size_t len = 0;
   while ((read = getline(&line, &len, fp)) != -1){
       int offset = atoi(line) & 255; // Pick up just 8 rightmost bits
       //printf("Offset:%d\n",offset);
       int page = atoi(line) & 65280; // Pick up just 8 leftmost bits
       //printf("P#:%d\n",page);
       // Why do we need 8 different shifts?
       // Because page var has leftmost bits which it calculates additional number
       int pageNumber = page >> 8; // right shift is like dividing to two
       //printf("page table num:%d\n",pageNumber);
       int tlb_hit = 0;
       for(int i=0; i<TLB_SIZE;i++){
         if(tlb[i][0]==pageNumber){
           tlb_hit = 1;
           printf("TLB HIT\n");
           break; // Leave the loop
         }
       }
      // Count page faults
      if(virtual_memory[pageNumber][0] < 0 && !tlb_hit){
            pageFaultCount++;
            srand(time(NULL));
            // Check Page Table
            //Eviction and replacement algorithms
      }
      // Calculate Physical Address
      physicalAddress = (physical_mem[virtual_memory[pageNumber][0]] * FRAME_SIZE) + offset;
      printf("Physical Address:%d\n",physicalAddress);

   }
  //Calculate the percentage of page faults
  double pageFaultRate = (double) pageFaultCount * 100;
  printf("\nPage Fault Rate: %.2f\n",pageFaultRate);

  free(line);
  fclose(fp);
  return 0;
}
