#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


//si and so bits stay at 0 for me


int main()
{
	void* ptr[10];
	for(int i=0;i<10;i++)
	{
		ptr[i] = malloc(10000000);
		memset(ptr[i],0,10000000);
		sleep(1);
	}
}