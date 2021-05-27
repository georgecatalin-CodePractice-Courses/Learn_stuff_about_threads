#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>  //this is used to access the exit() function
#include <unistd.h> //this is used to access the execv() and fork() functions
#include <sys/wait.h> //this is used to access the waitpid() function
#include <errno.h> //this is used to access the special variable errno which provides information for the specific cause of the errors


int my_function(char *cmd); //this is the prototype of the function

int main(int argc, char **argv)
{
	/* ***  The function my_function triggers and waits for the execution of the command "/bin/bash -c <cmd>".
	*** This function returns -1 in case of error or the exit code of the new process being executed
	*** */

	my_function("ls -lha");
	return 0;
}


int my_function(char *cmd)
{
	int status;
	pid_t pid;

	pid=fork(); //create a new process from the current process;

	if(pid==-1)
	{
		return -1;
	}
	else if(pid==0)
	{
			//in this case it means we are in the child process, the newly generated process
			char *argv[]={"vim","/home/georgeca/myPoem.txt",NULL};

			int ret=execv("/bin/bash/vim",argv);

			if(ret==-1)
			{
				perror("execv:");
			}

			exit(EXIT_SUCCESS);
	}

	if(waitpid(pid,&status,0)==-1) //in case of success waitpid() returns the pid of the processes whose status just modified, in case of error waitpid() returns -1
	{
		return -1;
	}
	else if(WIFEXITED(status)) //WIFEXITED returns true of the child exited normally
	{
		//this returns the code when child process exited
		return WEXITSTATUS(status);
	}

	return -1;
}




