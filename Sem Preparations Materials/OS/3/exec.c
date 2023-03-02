//Difference between fork() and vfork() : Sharing
// Family of exec functions
// Normal and abnormal termination

#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int argc, char *argv[])
{
	int f;
	
	write(1,"New Program", 9);
	f=fork();
	
	if (f==0)
	{
		//int execv(const char *path, char *const argv[]);
		//path: should point to the path of the file being executed. 
		//argv[]: is a null terminated array of character pointers.
		char *args[]={"./halo",NULL};
        	execv(args[0],args);
	}	
	
	if (f>0)
	{
		 int status;
		 wait(&status);
		 if ( WIFEXITED(status) )
		 {
		 	write(1,"Normal Termination of Child", 26);
		 }
	}
	
	
// Compilation : cc filename.c
// Execute : ./a.out parameter 1 parameter 2.......)	
}


