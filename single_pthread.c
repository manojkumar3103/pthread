#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
void* func()
{
    printf("Hello\n");
}
int main()
{
    pthread_t t1;
    pthread_create(&t1,NULL,func,NULL);
    pthread_join(t1,NULL);
    return 0;
}