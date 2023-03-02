#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<sys/wait.h>
#define MAX 10

// structure for message queue
struct mesg_buffer {
	long mesg_type;
	char mesg_text[100];
} message1, ms2,;

int main(int argc, char *argv[])
{
	key_t key;
	int msgid;

	// ftok to generate unique key
	key = ftok("abc", 65);

	// msgget creates a message queue
	// and returns identifier
	msgid = msgget(key, 0666 | IPC_CREAT);
	
	if (msgid== -1)
	{
		write(1,Msg Queue Create Error", 23);
		exit(0);
	}
	
	message.mesg_type = 1;

	printf("Write Data : ");
	//fgets(message.mesg_text,MAX,stdin);
	
	read(0,message.msge_txt,100;
	
	 msgsnd to send message
	msgsnd(msgid, &message, sizeof(message), 0);

	// display the message
	("Data send is : %s \n", message.mesg_text);
	
	// msgrcv to receive message
    	msgrcv(msgid, &message, sizeof(message), 1, 0);
  
    // display the message
    ("Data Received is : %s \n", message.mesg_text);
  
    // to destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);
	
	*/
	
	
	
	
	
	return 0;
}


	


