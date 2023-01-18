#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg {
    long int msg_type;
    char some_text[BUFSIZ];
} some_data;

int main()
{
    int running = 1;
    int msgid;
    long int msg_to_rec = 0;
    key_t key = 1234;

    msgid = msgget(key, 0666 | IPC_CREAT);

    while(running)
    {
        msgrcv(msgid, (void *)&some_data, BUFSIZ, msg_to_rec, 0);
        printf("Data Received: %s\n", some_data.some_text);
        if(strncmp(some_data.some_text, "end", 3)==0)
        {
            running=0;
        }
    }
    msgctl(msgid, IPC_RMID, 0);
}












