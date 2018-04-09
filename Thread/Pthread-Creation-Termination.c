
// Thread Creation and Termination

#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

void* PrintHello(void* data){

  int *my_data = (int*)data; // Data gets by thread
  int val = * my_data;
  printf("Hello from new thread - got %d\n", val);
  pthread_exit(NULL);

}
int main() {

  int rv; // Return Value
  pthread_t thread_id; // Thread's ID (int)
  int data_passed = 5; // Data passed to the new thread

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
  rv = pthread_create(&thread_id, NULL, PrintHello, &data_passed);

  if(rv)
  {
    printf("Error: return code from pthread_create is %d\n", rv);
    return (0);
  }
  printf("\nCreated new thread (%d) .... \n", (int)thread_id);

  // Terminate the thread
  pthread_exit(NULL);


}
