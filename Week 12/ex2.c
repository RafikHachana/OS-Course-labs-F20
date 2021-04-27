#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_INPUT_SIZE 255
#define MAX_PATH_SIZE 255

int main(int argc, char *argv[])
{
	bool append  = false;
	if(strcmp("-a",argv[1])==0) append = true;  //check for the append option

	int offset = append?2:1;  //offset to parse the file names from the list of arguments


	FILE* out[argc-offset];

	for(int i=0;i<argc-offset;i++)
	{
		if(append) out[i] = fopen(argv[i+offset],"a");  //file will be opened differently depending on the append option
		else out[i] = fopen(argv[i+offset],"w");
	}

	char input[MAX_INPUT_SIZE];

	//read the whole input

	
    fgets(input, MAX_INPUT_SIZE, stdin);  
    

	//print it to stdout
	printf("%s\n",input );  
	//write it to the file
	for(int i=0;i<argc-offset;i++)
	{
		fprintf(out[i], "%s\n",input); 
		fclose(out[i]);
	}

}