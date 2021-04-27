#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	printf("Welcome to the (not so simplistic) shell!\nWrite any command below to execute it,  write \"exit\" to quit the shell.\n");
	while(1)
	{
		char t[500];
		printf(">  ");
		fgets(t,500,stdin);
		if(strcmp(t,"exit\n")==0) return 0;
		int tmp= fork();
		if(tmp==0)
		{
			system(t);
			return 0;
		}
	}
}