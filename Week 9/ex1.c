#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


#define AGING_COUNTER_SIZE 30



int main()
{
	int frames;
	printf("Enter the number of page frames in physical memory:\n");
	scanf("%d",&frames);

	int* loaded_page = (int*)malloc(frames*sizeof(int));
	int* aging_counter = (int*)malloc(frames*sizeof(int));

	memset(aging_counter,0,frames*sizeof(int));
	memset(loaded_page,-1,frames*sizeof(int));

	int misses= 0;
	int hits  = 0;


	FILE *input = fopen("input.txt", "r");


	int ref;
	while(fscanf(input,"%d",&ref)==1)
	{
		bool hit = false;
		for(int i=0;i<frames;i++)
		{
			aging_counter[i] = aging_counter[i] >> 1;
			if(loaded_page[i]==ref)
			{
				aging_counter[i]+= 1<<(AGING_COUNTER_SIZE-1);
				hit = true;       
			}
		}
		if(hit)
		{
			hits++;
			continue;
		}
		int min_index =0;
		for(int i=0;i<frames;i++)
		{
			if(aging_counter[i]<aging_counter[min_index]) min_index = i;
		}
		aging_counter[min_index] = 1<<(AGING_COUNTER_SIZE-1);
		loaded_page[min_index] = ref;
		misses++;
	}



	double ratio = (double)hits/misses;
	printf("Hits: %d/ Misses %d --> Ratio = %.5f\number", hits,misses,ratio);


	fclose(input);
}