#include<stdio.h>
#include<pthread.h>
int x=0;
pthread_mutex_t lock;
void* func1()
{
    pthread_mutex_lock(&lock);
    for(int i=0;i<100000;i++)
    {
        x++;
    }
    pthread_mutex_unlock(&lock);
}
int main()
{
    pthread_t t1,t2;
    pthread_mutex_init(&lock,NULL);
    if(pthread_create(&t1,NULL,func1,NULL)!=0)
    {
        return 1;
    }
    if(pthread_create(&t2,NULL,func1,NULL)!=0)
    {
        return 2;
    }
    if(pthread_join(t1,NULL)!=0)
    {   
        return 3;
    }
    if(pthread_join(t2,NULL)!=0)
    {
        return 4;
    }
    pthread_mutex_destroy(&lock);
    printf("%d\n",x);
    return 0;
}