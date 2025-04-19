#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
pthread_mutex_t barrier=PTHREAD_MUTEX_INITIALIZER;
void *roll_dice(void* arg)
{
        pthread_mutex_lock(&barrier);
        int * random_num= (int *)arg;
        *random_num= rand()%6+1;
        printf("The random number is %d\n",*(int*)random_num);
        free(random_num);
        sleep(1);
        pthread_mutex_unlock(&barrier);
}

int main()
{
    pthread_t th[5];
    void* result;
    srand(time(NULL));
    for(int i=0;i<5;i++)
    {
        int* random_num= malloc(sizeof(int));
        if(pthread_create(th+i,NULL,roll_dice,random_num)!=0)
        {
            perror("Failed to create thread");
            exit(1);
        }
    }

    for(int i=0;i<5;i++)
    {
        if(pthread_join(th[i],NULL))
        {
            perror("Failed to join thread");
            exit(1);
        }
    }
    pthread_mutex_destroy(&barrier);
    return 0;
}