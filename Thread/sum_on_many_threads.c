#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct sum_runner_struct {
   long long limit;
   long long answer;
};
 // Thread function to generate sum of 0 to N
 void* sum_runner(void * arg)
 {
    struct sum_runner_struct *arg_struct = (struct sum_runner_struct*) arg;
    long long sum=0;
    for(long long i=0; i<=arg_struct->limit; i++){
      sum +=i;
    }
    arg_struct->answer = sum;
    pthread_exit(0);
 }

 int main(int argc, char const *argv[]) {
   if (argc<2){
     printf("Usage: %s <num 1> <num 2> ... <num-n>\n",argv[0] );
     exit(-1);
   }
   int num_args = argc -1; // Because the first argument is for the filename
   // Set up thread
   pthread_t tids[num_args];
   struct sum_runner_struct args[num_args];

   for(int i=0; i<num_args; i++){
      args[i].limit = atoll(argv[i+1]);
      pthread_attr_t attr;
      pthread_attr_init(&attr);
      pthread_create(&tids[i], &attr, sum_runner, &args[i]);
   }
   // Wait untill thread is done its work
   for(int i=0;i<num_args;i++){
      pthread_join(tids[i], NULL);
      printf("Sum is %lld\n", args[i].answer);
   }


 }
