#include<stdio.h>
#include<limits.h>
#include<float.h>

int main()
{
	int a;
	float b;
	double c;
	
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	
	printf("int variable: size %ld , max value %d\n", sizeof a, a);
	printf("float variable: size %ld , max value %f\n", sizeof b, b);
	printf("double variable: size %ld , max value %f\n", sizeof c, c);
	
	return 0;
}
