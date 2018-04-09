#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
long long sum =0;

void* sum_runner (void * data){
  long long *limit_ptr = (long long*)data;
  long long limit = *limit_ptr;
  for(long long i=0;i<=limit;i++){
    sum+=i;
  }
  pthread_exit(NULL);
}
int main(int argc, char const *argv[]) {
  if(argc<2){
    printf("Usage: %s <num>\n",argv[0]);
    exit(-1);
  }
  long long limit = atoll(argv[1]);
  pthread_t tid;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  int return_value = pthread_create(&tid, &attr, sum_runner, &limit);
  if(return_value){
    printf("Error: pthread_create generates error:%d\n",return_value);
    return(0);
  }
  //Do other stuff here
  printf("Do stuff here\n");
  //wait until the thread finished
  pthread_join(tid, NULL);
  printf("Sum is %lld\n", sum);


}
