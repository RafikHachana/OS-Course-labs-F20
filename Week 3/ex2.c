#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int* t,int n);

int main()
{
	int* a;
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	
	printf("Enter the elements of the array: \n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	
	bubble_sort(a,n);
	
	printf("Array sorted in non-decreasing order:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
	return 0;
}

void bubble_sort(int* t,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(t[j]>t[j+1])
			{
				int tmp = t[j];
				t[j] = t[j+1];
				t[j+1] = tmp;
			}
		}
	}
}
