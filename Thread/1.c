// Thread Creation and Termination
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void* PrintHello(void* data){
  int *my_data = (int*)data;
  int val = * my_data;
  printf("Hello from new thread- got %d\n",val );
  pthread_exit(NULL);
}
int main()
{
  pthread_t tid;
  int data_passed = 5;
  int return_value;
  return_value = pthread_create(&tid, NULL, PrintHello, &data_passed);
  if(return_value){
    printf("Error: retuen code frm pthread_create is %d\n", return_value);
  }
  //pthread_join(tid, NULL);
  printf("\nCreated new thread (%lld).....\n",(long long)tid );
  pthread_exit(NULL);

}
