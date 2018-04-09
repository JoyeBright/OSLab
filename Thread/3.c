#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
struct sum_runner_strucr{
  long long limit;
  long long answer;
};
void* sum_multiple_runner (void* data){
  struct sum_runner_strucr *args_struct = (struct sum_runner_strucr*) data;
  long long sum = 0;
  for(int i=0;i<=args_struct->limit;i++){
    sum+=i;
  }
  args_struct->answer = sum;
  pthread_exit(NULL);
}
int main(int argc, char const *argv[]) {
  if(argc<2){
    printf("Usage: %s <num 1> <num 2> .... <num n>\n",argv[0]);
    return 0;
  }
  int num_args = argc -1;
  pthread_t tid[num_args];
  struct sum_runner_strucr args[num_args];
  for(int i=0;i<num_args;i++){
    args[i].limit = atoll(argv[i+1]);
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int rv= pthread_create(&tid[i], &attr, sum_multiple_runner, &args[i]);
    if(rv){
      printf("Error: Pthread_create generates error %d\n",rv);
      exit(-1);
    }
  }
  for(int i=0;i<num_args;i++){
    pthread_join(tid[i], NULL);
    printf("Sum of thread %lld is %lld\n",(long long)tid[i],args[i].answer);
  }

}
