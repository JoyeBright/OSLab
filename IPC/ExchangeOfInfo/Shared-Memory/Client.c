// Shared memory is very fast
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define SHSIZE 27
int main() {
  key_t key;
  key = 5678;
  int shmid = shmget(key,SHSIZE,0666);
  if(shmid<0){
   printf("Shmid!");
   exit(1);
  }
  char *shm = (char*)shmat(shmid,NULL,0);
  if(shm ==(char*)-1){
    printf("Shmat");
    exit(1);
  }
  for(char *s = shm;*s!='\0';s++)
     putchar(*s);
  putchar('\n');
  *shm = '*';
  exit(0);
}
