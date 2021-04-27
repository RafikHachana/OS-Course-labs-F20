#include <stdio.h>
#include <unistd.h>

int main()
{
	for(int i=0;i<5;i++) fork();
	sleep(5000);
}

/*
	fork creates a new process, so calling it in one process results in 2 processes
	--> the number of processes doubles each time fork is called
	That's why in the first case (3 forks), we end up with 8 = 2^3 processes
	and in the second case (5 forks) we end up with 32 = 2^5 processes
*/