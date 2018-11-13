#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* PrintHello (void* data){
  int* data_ptr = (int*)data;
  int receivedData = * data_ptr;
  printf("Hello from new thread-Got %d\n",receivedData);
  pthread_exit(NULL);
}

int main() {

  pthread_t tid;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  int data_passed = 5;

  int rv = pthread_create(&tid, &attr, PrintHello, &data_passed);
  if(rv){
    printf("Error: pthread_create generates error %d\n",rv);
    return 0;
  }
  // pthread_join is a functionality of pthread library which allows
  // the originating(main) thread to wait for the completion of all its
  // spawned thread's tasks
  pthread_join(tid, NULL);
  printf("The new thread id: %lld\n",(long long)tid);
  pthread_exit(NULL);
}
