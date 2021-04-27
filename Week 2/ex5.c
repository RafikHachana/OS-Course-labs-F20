#include<stdio.h>
#include<string.h>


void triangle(int n);
void square(int n);
void right_triangle(int n);

int main(int argc, char *argv[])
{
	char shape[1000];
	sscanf(argv[1],"%s",shape);
	
	int n;
	sscanf(argv[2],"%d",&n);
	
	if(n<=1) return 0;
	
	if(strcmp(shape,"triangle") == 0) triangle(n);
	if(strcmp(shape,"square") == 0) square(n);
	if(strcmp(shape,"right_triangle") == 0) right_triangle(n);
	
	return 0;
}

void triangle(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++) printf(" ");
		for(int j=1;j<=2*i-1;j++) printf("*");
		for(int j=1;j<=n-i;j++) printf(" ");
		printf("\n");
	}
}

void square(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) printf("*");
		printf("\n");
	}
}

void right_triangle(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++) printf("*");
		printf("\n");
	}
}
