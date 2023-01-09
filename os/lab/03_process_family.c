#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
Fork returns, 
    0 for Child
    processId of child for the parent
*/

// int main()
// {
//     if(fork() == 0)
//     {
//         printf("Im Childish %d\n", getpid());
//     } 
//     else
//     {
//         printf("Im Parental %d\n", getpid());
//     }
        
// }

int value = 5;

int main()
{
    pid_t pid;
    pid = fork();

    if(pid==0)
    {
        value += 15;
        printf("Statement 1: value = %d\n", value);
    }
    if(pid>0)
    {
        wait(NULL);
        printf("Statement 2: value = %d\n", value);
    }
    value += 10;
    printf("Statement 3: value = %d\n", value);
}