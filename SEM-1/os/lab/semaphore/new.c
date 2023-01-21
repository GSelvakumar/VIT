#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define CUSTOMERS 0
#define BARBERS 1
#define MUTEX 2
#define CHAIRS 5

void signaling(int semId, int semNum, struct sembuf *semaphore)
{
  semaphore->sem_num = semNum;
  semaphore->sem_op = 1; // +1 for release
  semaphore->sem_flg = 0; //SEM_UNDO
  semop(semId, semaphore, 1); // id, (sops)structure specifiying the operations, no of operations(nsops)
}

void waited(int semId, int semNum, struct sembuf *semaphore)
{
  semaphore->sem_num = semNum;
  semaphore->sem_op = -1; // -1 for acquire
  semaphore->sem_flg = 0;
  semop(semId, semaphore, 1);
}

void initSem(int semId, int semNum, int val)
{
  union semnum
  {
  int val;
  struct semid_ds *buf;
  unsigned short *array;
  }argument;
  argument.val = val;
  semctl(semId, semNum, SETVAL, argument);
  /* Set the value of the individual semaphore referenced by the semnum argument to the value specified by the fourth argument to semctl*/
}

int main()
{
  key_t semKey = 1111;
  key_t shmKey = 2222;
  int semId, shmId;

  struct sembuf semaphore;
  /*
    struct sembuf {
    unsigned short sem_num;
    short sem_op;
    short sem_flag;
  }
 */
  int count = 1;
  int *waiting;

  shmId = shmget(shmKey, sizeof(int), 0666|IPC_CREAT);
  semId = semget(semKey, 3, 0666|IPC_CREAT);

  waiting = shmat(shmId, NULL, 0);
  *waiting = 0;

  initSem(semId, CUSTOMERS, 0);
  initSem(semId, BARBERS, 0);
  initSem(semId, MUTEX, 1);

  printf("There are %d chairs.\n", CHAIRS);

  if(fork())
  {
    //The Barber Part
    while(1)
      {
        waited(semId, CUSTOMERS, &semaphore);
        waited(semId, MUTEX, &semaphore);
        *waiting = *waiting-1;
        signaling(semId, BARBERS, &semaphore);
        signaling(semId, MUTEX, &semaphore);
        printf("The barber is now cutting hair\n");
        sleep(6);
      }
  }
  
  else
  {
    // The Customer Part
    while(1)
      {
        sleep(1);
        waited(semId, MUTEX, &semaphore);
        if(*waiting < CHAIRS)
        {
          printf("Customers %d is seated.\n", count++);
          *waiting = *waiting+1;
          signaling(semId, CUSTOMERS, &semaphore);
          signaling(semId, MUTEX, &semaphore);
        }
        else{
          printf("Customer %d left the shop.\n", count++);
          signaling(semId, MUTEX, &semaphore);
        }
      }
  }
}