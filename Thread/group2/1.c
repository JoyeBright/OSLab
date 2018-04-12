#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* PrintHello(void* data_passed){
  int* received_data = (int *) data_passed;
  int my_data = * received_data;
  printf("Hello from new thread-Got %d\n",my_data);
  pthread_exit(NULL);
}
int main() {
  pthread_t tid;
  int data_passed = 5;
  int return_value = pthread_create(&tid, NULL, PrintHello, &data_passed);
  if(return_value){
    printf("Error: pthread_create generates error %d\n",return_value);
    return 0;
  }
  pthread_join(tid, NULL);
  // Do other stuff here
  printf("The main thread_id:%lld\n",(long long)tid);
  pthread_exit(NULL);
}
