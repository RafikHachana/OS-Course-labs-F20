#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>


int main()
{
	//get the size of the source file
	struct stat stats_source;
	stat("ex4.txt",&stats_source);
	int source_size = stats_source.st_size;

	//resize the destination file
	truncate("ex4.memcpy.txt",source_size);


	//map the source file to memory
	int f1 = open("ex4.txt",O_RDWR);
	char* source = mmap(NULL, source_size,PROT_READ|PROT_WRITE,MAP_SHARED,f1,0);


	//map the destination file to memory
	int f2 = open("ex4.memcpy.txt",O_RDWR);
	char* destination = mmap(NULL, source_size,PROT_READ|PROT_WRITE,MAP_SHARED,f2,0);


	
	//copy the content
	memcpy(destination,source,source_size);
}