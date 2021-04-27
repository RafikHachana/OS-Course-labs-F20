#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
	DIR *dir = opendir("./tmp");


	char path[300];

	struct stat stats;  

  	struct dirent* curr;

  	while((curr=readdir(dir))!=NULL)
  	{
  		if(strcmp(curr->d_name, ".") ==0 || strcmp(curr->d_name, "..") == 0) continue;

  		sprintf(path,"%s%s","./tmp/",curr->d_name);
  		stat(path, &stats);

  		if(stats.st_nlink >= 2)
  		{
  			printf("Links to %s\n", path);
  			DIR *tmp = opendir("./tmp");
  			char link_path[256];

			struct stat link_stats;  

  			struct dirent* link_curr;	

  			while((link_curr=readdir(dir))!=NULL)
		  	{
		  		sprintf(link_path,"%s%s","./tmp/",link_curr->d_name);
		  		stat(link_path, &link_stats);
		  		if(link_stats.st_ino==stats.st_ino) printf("%s\n", link_curr->d_name);
		  	}
		  	printf("\n");
  		}
  	}
}