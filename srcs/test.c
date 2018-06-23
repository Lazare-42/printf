#include <stdio.h>
#include "../libft/includes/libft.h"
#include "../includes/printf.h"
#include <stdlib.h>

char	*print_bits(void *ptr, int size) 
{
	int i;
	int bit_nbr = 0;
	char *result;
	char *test;
	int		j;

	i = 7;
	j = 0;
	test = ptr;
	if (!(result = ft_strnew(size * 10)))
		return (NULL);
	while (j < size)
	{
		result[bit_nbr] = (test[j] & (1 << i)) ? '1' : '0';
		bit_nbr++;
		(i == 4) ? result[bit_nbr] = ' ' : 0;
		(i == 4) ? bit_nbr++ : 0;
		(i == 0) ? result[bit_nbr] = ' ' : 0;
		(i == 0) ? j++ : 0;
		(i == 0) ? bit_nbr++ : 0;
		(i == 0) ? i = 8 : 0;
		i--;
	}
	return (result);
}

int main()
{
	/*
	   union	uTes(t
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

	/*
	int test = 8;

	if (ft_check_endianness())
		ft_symetric_byte_swap((void*)&test, sizeof(int));
		*/


	/*
	   printf("this is compilator approximation\n %d : \ntest", pp);

	   printf("%*.*d\n", 14, 30, 311);
	   printf("%*.*d\n", 14, -30, 311);
	   printf("%*.*f\n", 14, -1, test);
	   ft_printf("%*.*d\n", 14, 30, 311);
	   printf("\n%*.*d\n", 14, 1, 311);
	 */

//	ft_printf("%10.s", "314.99");
 //      printf("\n%10.s", "314.99");
	 
	/*
	int zero;

	zero = 0;
printf("'%p'\n",(void*)0);
printf("'%.p'\n",(void*)0);
ft_printf("'%p'\n",(void*)0);
ft_printf("'%.p'\n",(void*)0);
*/
printf("%5.5s\n","heheheheheheheheeheh");
ft_printf("%5.5s\n","heheheheheheheheeheh");
	/*
	   ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr(print_bits((void*)&test, sizeof(int)));
	   printf("this is floaty : %f\n", floaty);
	   printf("this is floaty : %F\n", floaty);
	   printf("this is floaty : %e\n", floaty);
	   printf("this is floaty : %E\n", floaty);
	 */
}
