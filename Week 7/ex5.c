#include <stdio.h> 
#include<stdlib.h> //to be able to use malloc


int main() { 
	char **s; //this is a pointer to a string

	s = (char**)malloc(sizeof(char*)); //allocate memory ...

	char foo[] = "Hello World"; 
	*s = foo;  //... so that *s is allocated in memory
	printf("s is %p\n",s); //s is a pointer value (memory address) and not a string, we should use %p instead of %s
	s[0] = foo;
	printf("s[0] is %s\n",s[0]); 
	return(0); 
	}