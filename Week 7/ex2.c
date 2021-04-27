#include<stdio.h>
#include<stdlib.h>

int main()
{
	int* array;
	int n;
	printf("Enter the size of the array :  ");
	scanf("%d",&n);
	array = (int*) malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		array[i] = i;
	}

	for(int i=0;i<n;i++)
	{
		printf("%d\n", array[i]);
	}

	free(array);
}