#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <fcntl.h>
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
		write(1, "Msg Queue Create Error",23);
		//exit(0);
	}
	
	return 0;
}


	


