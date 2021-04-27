#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE* random = fopen("/dev/random","r");
	FILE* out = fopen("ex1.txt","w");

	char* random_string = (char*)malloc(20);  //allocate 20 bytes for the symbols

	fread(random_string, 1, 20, random); //read 20 bytes of random symbols
	fprintf(out, random_string);  //write the result to the file
	fclose(out);
	fclose(random);
}