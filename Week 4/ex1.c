#include <stdio.h>
#include<unistd.h>

/*
	fork returns the pid of the child to the parent, and 0 to the child, 
	that's why n is always 0 for the child, and it is the pid of the child for the parent

	running the program 10 times using the bash shell script, we can observe that pid_child = pid_parent +1
*/


int main()
{
	int n = fork();
	
	if(n!=0)
	{
		printf("Hello from parent [%d - %d]\n",getpid(),n);
	}
	else
	{
		printf("Hello from child [%d - %d]\n",getpid(),n);
	}
}