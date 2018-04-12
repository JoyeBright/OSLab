#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
long long sum=0;
void* sum_runner(void* data){
  long long* my_data = (long long*) data;
  long long constraint = * my_data;
  for(int i=0;i<=constraint;i++){
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
  pthread_create(&tid,&attr,sum_runner,&limit);
  // Do other stuff
  
  pthread_join(tid, NULL);
  printf("Sum is %lld\n",sum);
}
