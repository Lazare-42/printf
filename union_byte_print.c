#include <stdio.h>
#include "./libft/includes/libft.h"

void print_bytes(void *ptr, int size) 
{
	unsigned char *p = ptr;
	int i;
	int byte_number = 0;

	for (i=0; i<size; i++) {
		byte_number++;
	printf("this is byte_number %d : ", byte_number);
		if (p[i] & 128) 
			printf("%d", 1);
		else
			printf("%d", 0);
		if (p[i] & 64) 
			printf("%d", 1);
		else
			printf("%d", 0);
		if (p[i] & 32) 
			printf("%d", 1);
		else
			printf("%d", 0);
		if (p[i] & 16) 
			printf("%d ", 1);
		else
			printf("%d ", 0);

		if (p[i] & 8) 
			printf("%d", 1);
		else
			printf("%d", 0);
		if (p[i] & 4) 
			printf("%d", 1);
		else
			printf("%d", 0);
		if (p[i] & 2) 
			printf("%d", 1);
		else
			printf("%d", 0);
		if (p[i] & 1) 
			printf("%d\n", 1);
		else
			printf("%d\n", 0);
	}
	printf("\n");
}

#include <math.h>

int main()
{
int num = 1;

if (*(char *)&num == 1)
{
    printf("Little-Endian\n");
}
else
{
    printf("Big-Endian\n");
}	
	union	uTest
	{
		unsigned int integer;
		double test;
	}		uniontest;
//	uniontest.integer = 4294967296 - 1;
	uniontest.integer = 1;
	printf("0 if it is not a number %d, %d\n", (ft_isinf((double)(0))), (isinf((double)(0))));
	printf("%lu size of unsigned int in bytes\n", sizeof(unsigned int));
	printf("%lu size of double in bytes\n", sizeof(double));
	printf("%lu size of double in bytes\n", sizeof(unsigned long));
	print_bytes(&uniontest, 4);
}
