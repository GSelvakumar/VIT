#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* myturn(void * arg) {
    int *iptr = (int *)arg;
    for(int i=0; i<8; i++)
    {
        sleep(1);
        printf("My Turn! %d %d\n", i, *iptr);
        (*iptr)++;
    }
    return NULL;
}

void yourturn() {
    for(int i=0; i<4; i++)
    {
        sleep(2);
        printf("Your Turn! %d\n", i);
    }
}

int main()
{
    pthread_t newthread;
    int v = 5;
    pthread_create(&newthread, NULL, myturn, &v);
    //myturn();
    yourturn();
    pthread_join(newthread, NULL); // waits for specific thread finishs running
    printf("thread done v = %d", v);
}