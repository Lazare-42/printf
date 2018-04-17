#include <stdio.h>
#include <stdlib.h>

void print_bits(int ptr, int size) 
{
	int i;


	for (i = size * 8 - 1; i > -1; i--) {
        (ptr & (1 << i)) ? putchar('1') : putchar('0');
		(i != size * 8 - 1 && !(i % 8)) ? putchar(' ') : 0;
		(i != size * 8 + 1 && !(i % 4)) ? putchar(' ') : 0;
	}
	printf("\n");
}

#include <math.h>

int main()
{
	/*
	union	uTest
	{
		unsigned int integer;
	}		uniontest;
	*/
//	uniontest.integer = 4294967296 - 1;
		int test;

	test = pow(2, 31) - 1;
	test *= -1;
	printf("%lu size of int in bytes\n", sizeof(float));
	print_bits(test, sizeof(test));
}
