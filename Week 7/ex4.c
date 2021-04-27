#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>


int min(int a,int b)   //utility function to get the minimum of two integers
{
	return (a<b)?a:b;
}

/*
	Since there is no standard platform-independent way to find the size of dynamically allocated memory, 
	I provided my implementation with an extra parameter: the old size of the memory
*/


void* reallocate(void* ptr, size_t size,size_t old_size)
{
	if(ptr==NULL) return malloc(size);
	if(size==0)
	{
		free(ptr);
		return NULL;
	}
	void* newptr = malloc(size); //allocate new memory

	size_t cpy_size = min(old_size,size); //determine the size of data to be copied from the old pointer to the new
	
	newptr = memcpy(newptr,ptr,cpy_size);    //copy the data

	free(ptr);  //free the old memory

	return newptr;  //return a pointer to the new memory location
}


//I used the code template from exercise 3 as a driver code for my function


int main(){
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = (int*)malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = (int*)reallocate(a1,n2*sizeof(int),n2*sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	for(int i=n1;i<n2;i++)
	{
		a1[i] = 0;
	}
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ",a1[i]);
	}
	printf("\n");
	free(a1);
	//Done with array now, done with program :D
	
	return 0;
}