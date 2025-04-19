#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>

pthread_mutex_t mutex;
sem_t semEmpty;
sem_t semFull;
int buffer[10];
int count=0;

void *producer(void *arg)
{
    while(1)
    {
    sem_wait(&semEmpty);
    pthread_mutex_lock(&mutex);
    buffer[count++]=rand()%100;
    printf("Produced: %d\n", buffer[count - 1]);
    pthread_mutex_unlock(&mutex);
    sem_post(&semFull);
    //pthread_mutex_unlock(&mutex);
    sleep(1);
    }
}

void *consumer(void *arg)
{
    while(1)
    {
    sem_wait(&semFull);
    pthread_mutex_lock(&mutex);
    int item = buffer[--count];
    printf("Consumed: %d\n", item);
    pthread_mutex_unlock(&mutex);
    sem_post(&semEmpty);
    //pthread_mutex_unlock(&mutex);
    sleep(1);
    }
}

int main()
{
    pthread_t consumer_th,producer_th;
    sem_init(&semEmpty,0,10);
    sem_init(&semFull,0,0);
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&producer_th,NULL,producer,NULL);
    pthread_create(&consumer_th,NULL,consumer,NULL);
    pthread_join(producer_th,NULL);
    pthread_join(consumer_th,NULL);
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutex);
    return 0;
}
