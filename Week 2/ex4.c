#include<stdio.h>

void swap(int* x,int* y);

int main()
{
	int a,b;
	printf("Enter a value for variable a: ");
	scanf("%d",&a);
	printf("Enter a value for variable b: ");
	scanf("%d",&b);
	
	swap(&a,&b);
	
	printf("After swapping: a = %d and b = %d\n",a,b);
}


void swap(int* x,int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
	
	
