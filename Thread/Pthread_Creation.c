
// Thread Creation and Termination
#include <stdio.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>

long long sum = 0;

void* sum_runner(void* data){
  long long *my_data = (long long*)data; // Data gets by thread
  long long val = * my_data;
  for(long long i=0;i<=val;i++){
    sum +=i;
  }
  pthread_exit(NULL);
}
int main(int argc, char const *argv[]) {
  if(argc>2){
    printf("Usage: %s <num>\n",argv[0]);
    return 0;
  }
  int rv; // Return Value
  pthread_t thread_id; // Thread's ID (int)
  long long data_passed = atoll(argv[1]); // Data passed to the new thread

  // Create a new thread that will execute 'PrintHello'
  /*
     Note: all of the arguments are pointers
     The first arg is a pointer to thread_id,
     the second arg is used to set some attributes for the new thread_id
     (if you use NULL it sets default values)
     the third is void* (*start_routine)(void*), accepts void* as an arg and also returns a void* as a rv
     what does it show? it indicates that is possible to pass an arbitrary piece of data to our new thread,
     and that our new thread can return an arbitrary piece of data when it finishes.
     how do we pass our thread an arbitrary argument? we use the fourth arg to call.
  */
  rv = pthread_create(&thread_id, NULL, sum_runner, &data_passed);
  if(rv)
  {
    printf("Error: return code from pthread_create is %d\n", rv);
    return (0);
  }
  printf("\nCreated new thread (%d) .... \n", (int)thread_id);
  pthread_join(thread_id, NULL);
  printf("\nsum: %lld\n", sum);
  // Terminate the thread
  pthread_exit(NULL);
}
