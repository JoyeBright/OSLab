#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
long long sum = 0;
void* Sum_Runner(void* data){
  long long* data_ptr = (long long*)data;
  long long constraint = * data_ptr;
  for(int i=0;i<=constraint;i++){
    sum+=i;
  }
  pthread_exit(NULL);
}
int main(int argc, char const *argv[]) {
  if(argc<2){
    printf("Usage: %s <N>\n",argv[0]);
    return 0;
  }
  long long limit = atoll(argv[1]);
  pthread_t tid;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_create(&tid,&attr,Sum_Runner,&limit);
  //Do other stuff here
  pthread_join(tid,NULL);
  printf("Sum is %lld\n",sum);
}
