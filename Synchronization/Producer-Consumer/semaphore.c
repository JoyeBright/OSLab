#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

int producer_count, consumer_count, buffer_length, *buffer, buffer_pos;
sem_t buffer_mutex, full_count, empty_count;
pthread_t *producers, *consumers;

int produce(pthread_t self){
     int i = 0;
     int item = 1 + rand() % 40; // generate 1 to 40 different number
     while(!pthread_equal(*(producers+i),self) && i<producer_count){
       i++;
     }
     printf("Producer %d produced %d\n", i+1, item);
     return item;
}
void consume(int item, pthread_t self){
  int i=0;
  while(!pthread_equal(*(consumers+i),self) && i < consumer_count){
    i++;
  }
  printf("Buffer:");
  for(i=0;i<buffer_pos;++i){
    printf("%d",*(buffer+i));
  }
  printf("\n Consumer %d consumed %d \n Current Buffer length: %d\n",i+1, item, buffer_pos);
}
void *producer(void *args){
  while(1){
    int item = produce(pthread_self());
    sem_wait(&empty_count);
    sem_wait(&buffer_mutex);
    ++buffer_pos; // Critical section
    *(buffer + buffer_pos) = item;
    sem_post(&buffer_mutex); // unlock Semaphore
    sem_post(&full_count); // unlock Semaphore
    sleep(1 + rand() % 3);
  }
  return NULL;
}
void *consumer(void *args){
  int item;
  while(1){
    sem_wait(&full_count);
    sem_wait(&buffer_mutex);
    item = * (buffer + buffer_pos);
    consume(item, pthread_self());
    --buffer_pos;
    sem_post(&buffer_mutex);
    sem_post(&empty_count);
    sleep(1+rand()%5);
  }

  return NULL;
}
int main(){
  int err;
  //Using Pseudo Random Number
  //why pseudo random?
  srand(time(NULL));
  //First and 2nd semaphore
  sem_init(&buffer_mutex, 0, 1);
  sem_init(&full_count, 0, 0);


  printf("Enter the number of Producer:");
  scanf("%d",&producer_count);
  producers = (pthread_t*) malloc(producer_count * sizeof(pthread_t));

  printf("Enter the number of Consumer:");
  scanf("%d",&consumer_count);
  consumers = (pthread_t*)malloc(consumer_count * sizeof(pthread_t));

  printf("Enter the buffer capacity:");
  scanf("%d",&buffer_length);
  buffer = (int*) malloc(buffer_length * sizeof(int));
  //3rd Semaphore
  sem_init(&empty_count, 0, buffer_length);
  // Create the producers
  for(int i=0;i<producer_count;i++){
    err = pthread_create(producers+i, NULL, &producer, NULL);
    if(err != 0){
          printf("Error creating producer %d: %s\n", i+1, strerror(err));
    }else{
         printf("Successfully created producer %d\n", i+1);
    }
  }
  // Create the consumers
  for(int i=0;i<consumer_count;i++){
    err = pthread_create(consumers+i, NULL, &consumer, NULL);
    if(err !=0){
      printf("Error creating consumer %d: %s\n", i+1, strerror(err));
    }else{
      printf("Successfully created consumer %d\n", i+1);
    }
  }

  for(int i=0;i<producer_count;i++){
    pthread_join(*(producers+i),NULL);
  }
  for(int i=0;i<consumer_count;i++){
    pthread_join(*(consumers+i),NULL);
  }

  return 0;
}
