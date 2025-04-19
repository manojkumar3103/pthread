#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define THREAD_NUM 6

sem_t t1;
pthread_mutex_t mutex;

void* thread(void * arg)
{
    int x=*(int*)arg;
    free(arg);
    sem_wait(&t1);
    pthread_mutex_lock(&mutex);
    printf("Thread %d is running\n",x);
    sleep(2);
    sem_post(&t1);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main()
{
    sem_init(&t1,0,1);
    pthread_mutex_init(&mutex,NULL);
    pthread_t th[THREAD_NUM];
    for(int i=0;i<THREAD_NUM;i++)
    {
        int *a=malloc(sizeof(int));
        *a=i;
        if(pthread_create(th+i,NULL,&thread,a)!=0)
        {
            printf("Error creating thread\n");
        }
    }

    for(int i=0;i<THREAD_NUM;i++)
    {
        if(pthread_join(th[i],NULL)!=0)
        {
            printf("Error joining thread\n");
        }
    }
    sem_destroy(&t1);
    return 0;
}