#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX_TEXT 512 // maximum length of msg allowed to send

struct my_msg {
    long int msg_type;
    char some_text[MAX_TEXT];
} some_data;

int main()
{
    int running = 1;
    int msgid;
    char buff[50];
    key_t key = 1234;

    msgid = msgget(key, 0666 | IPC_CREAT);

    if (msgid == -1)
    {
        printf("Error in creating queue\n");
        exit(0);
    }

    while(running)
    {
        printf("Enter some text: \n");
        fgets(buff, 50, stdin);
        some_data.msg_type = 1;
        strcpy(some_data.some_text, buff);

        if (msgsnd(msgid, (void *)&some_data, MAX_TEXT, 0) == -1)
        {
            printf("Msg not sent\n");
        }
        if(strncmp(buff, "end", 3) == 0)
        {
            running = 0;
        }
    }
}











