/*
ftok - creates a key
shmget - uses the key and create a block and returns the block id
shmat - maps the block and get the ptr to the block
*/

// This program creates a shared memory segment, attaches itself to it and then writes some content into the shared memory segment.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>

int main()
{
    int i;
    void * shm_memory;
    char buff[100];
    int shmid;
    key_t key = 1234;

    shmid = shmget(key, 1024, 0666);

    printf("Key of shared memory is %d\n", shmid);

    shm_memory = shmat(shmid, NULL, 0);

    printf("Process attached at %p\n", shm_memory);

    // printf("Enter some data to write to shared memory: \n");

    // read(0, buff, 100);
    // strcpy(shm_memory, buff);
    // printf("You wrote: %s\n", (char *)shm_memory);

    printf("Read from shm: %s\n", (char *)shm_memory);
}
