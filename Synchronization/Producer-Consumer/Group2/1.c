#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

sem_t buffer_mutex, full_count, empty_count;
int producer_count, consumer_count, buffer_length, *buffer, buffer_pos = -1;
pthread_t *producers, *consumers;
int produce(pthread_t self){
  int i = 0;
  int item = 1 + rand() % 40;
  while(!pthread_equal(*(producers+i),self) && i < producer_count){
   i++;
  }
  printf("Producer %d produced item %d\n",i+1,item);
  return item;
}
void consume(int item, pthread_t self){
  int i=0;
  while(!pthread_equal(*(consumers+i),self) && i<consumer_count){
    i++;
  }
  printf("Buffer:");
  for(int i=0;i<buffer_length;i++){
    printf("%d",*(buffer +i));
  }
  printf("\nConsumer %d consumed item %d \n Current buffer length %d\n",i+1, item, buffer_pos);
}
void *producer(void *args){
  while(1){
    int item = produce(pthread_self());
    sem_wait(&empty_count);
    sem_wait(&buffer_mutex);
    ++buffer_pos; // Critical section
    *(buffer + buffer_pos) = item;
    sem_post(&buffer_mutex);
    sem_post(&full_count);
    sleep(1 + rand() % 3);

  }
  return NULL;
}
void *consumer(void *args){
  int item;
  while(1){
        sem_wait(&full_count);
        sem_wait(&buffer_mutex);
        item = *(buffer + buffer_pos);
        consume(item, pthread_self());
        --buffer_pos;
        sem_post(&buffer_mutex);
        sem_post(&empty_count);
        sleep(1+rand()%5);
  }

  return NULL;
}
int main(){
  int error;
  sem_init(&buffer_mutex, 0, 1);
  sem_init(&full_count, 0, 0);

  printf("Enter the number of producers");
  scanf("%d",&producer_count);
  producers = (pthread_t*)malloc(producer_count * sizeof(pthread_t));
  printf("Enter the number of consumers");
  scanf("%d",&consumer_count);
  consumers= (pthread_t*)malloc(consumer_count * sizeof(pthread_t));
  printf("Enter the buffer capacity");
  scanf("%d",&buffer_length);
  buffer = (int*)malloc(buffer_length * sizeof(int));

  sem_init(&empty_count, 0, buffer_length);
  for(int i=0;i<producer_count;i++){
    error = pthread_create(producers+i, NULL, &producer, NULL);
    if(error!=0){
      printf("Error creating producer %d : %s\n",i+1, strerror(error));
    }
    else{
      printf("producer %d created successfully!\n",i+1);
    }
  }
  for(int i=0;i<consumer_count;i++){
    error = pthread_create(consumers+i, NULL, &consumer, NULL);
    if(error!=0){
      printf("Error creating consumer %d : %s\n",i+1, strerror(error));
    }
    else{
      printf("consumer %d created successfully!\n",i+1);
    }
  }
  for(int i =0;i<producer_count;i++){
    pthread_join(*(producers+i), NULL);
  }
  for(int i =0;i<consumer_count;i++){
    pthread_join(*(consumers+i), NULL);
  }

return 0;

}
