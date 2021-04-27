#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>


int main()
{
	char* s = "This is a nice day";

	//resize the file
	truncate("ex1.txt",strlen(s));

	//writing the new string using map
	int f = open("ex1.txt",O_RDWR);
	char* map = mmap(NULL, strlen(s),PROT_READ|PROT_WRITE,MAP_SHARED,f,0);

	for(int i=0;i<strlen(s);i++)
	{
		map[i] = s[i];
	}
}