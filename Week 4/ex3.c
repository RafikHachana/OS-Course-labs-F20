#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	printf("Welcome to the simplistic shell!\nWrite any command below to execute it,  write \"exit\" to quit the shell.\n");
	while(1)
	{
		char t[500];
		printf(">  ");
		scanf("%s",t);
		if(strcmp(t,"exit")==0) return 0;
		system(t);
	}
}