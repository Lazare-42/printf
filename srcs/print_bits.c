#include <stdio.h>
#include "../libft/includes/libft.h"
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
//	printf("%.2s\n", "coucou");
//	printf("%.30d\n", 1);

//witdh : in dynamic and static form
	printf("%*d\n", 10, 311);
	printf("%10d\n", 311);

// width : in dynamic negative form
	printf("%*d\n", -10, 311);
	printf("%-10d\n", 311);

// precision 
	printf("%.*d\n", 20, 20);
	printf("%.10d\n", 311);


}
