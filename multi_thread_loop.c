#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int x=0;
pthread_mutex_t mutex;
int arr[10]={2,4,6,8,10,12,14,16,18,20};

void *thread(void * arg)
{
    int index=*(int*) arg;
    pthread_mutex_lock(&mutex);
    printf("value %d, ",arr[index]);
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_mutex_init(&mutex,NULL);
    pthread_t th[10];
    for(int i=0;i<10;i++)
    {
        void* arg=(void*) &i; //passing index as ar
        printf("started pthread : %d\n",i);
        if(pthread_create(th+i,NULL,thread,arg)!=0)
        {
            return 1;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(pthread_join(th[i],NULL)!=0)
        {
            return 2;
        }
        printf("ended pthread : %d\n",i);
    }
    pthread_mutex_destroy(&mutex);
    printf("%d\n",x);
    return 0;
}