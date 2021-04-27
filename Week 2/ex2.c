#include<stdio.h>
#include<string.h>

#define LENGTH 256

int main()
{
	char s[LENGTH];
	printf("Enter a string: ");
	//scanf("%s",s);
	fgets(s,LENGTH,stdin);
	printf("The string in reverse: ");
	for(int i=strlen(s)-1;i>=0;i--)
	{
		if(s[i]!='\n') printf("%c",s[i]);
	}
	printf("\n");
	
	return 0;
}
