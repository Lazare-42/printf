#include <stdio.h>
#include "../libft/includes/libft.h"
#include "../includes/printf.h"
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
//	uniontest.integer = 4294967296 - 1;
//	printf("%.2s\n", "coucou");
//	printf("%.30d\n", 1);

//witdh : in dynamic and static form, positive
	printf("%*d\n", 10, 311);
	printf("%10d\n", 311);
	printf("%*s\n", 10, "je traverse la nuit et la brume, langoisse et");
	printf("%10s\n", "je traverse la nuit et la brume, langoisse et");

//witdh : in dynamic and static form, negative
	printf("%*d\n", -10, 311);
	printf("%-10d\n", 311);

// precision 
// if negative : does not affect
// if positive and number : add 0s to the left so that total number printed are the one in precision
// if positive and string : print maximum that number of numbers
	ft_printf("s\n%%", 311, 2);
	*/
//	ft_printf("%%sdckjnsdckjnsdc\n% 0*.*d", 2, 3, 5);

	int test;

	test = 23232;
	ft_printf("%x", test);
	printf("\n%x", test);
}
