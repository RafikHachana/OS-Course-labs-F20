#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int n;
	sscanf(argv[1],"%d",&n);
	
	if(n<=1) return 0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++) printf(" ");
		for(int j=1;j<=2*i-1;j++) printf("*");
		for(int j=1;j<=n-i;j++) printf(" ");
		printf("\n");
	}
	
	return 0;
}
