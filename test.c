#include <stdio.h>
#include "includes/libft.h"
#include "includes/printf.h"
#include <stdlib.h>
#include <limits.h>

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

//ft_printf("\n\n\n\n%08x", 42);                       
//ft_printf("\n\n%-5d", -42);                       
//printf("\n\n%-5d", -42);                       
int main()
{
 int ret;

 ret = ft_printf("%%####.10%% {%####.10%}"); fflush(stdout);
 printf("\nret = %d\n", ret); fflush(stdout);
 ret = printf("%%####.10%% {%####.10%}"); fflush(stdout);
 printf("\nret = %d\n", ret); fflush(stdout);
 /*
 ret = ft_printf("{%%10%%} {%10%}");
 printf("\nret = %d\n", ret); fflush(stdout);
 ret = printf("{%%10%%} {%10%}"); fflush(stdout);
 printf("\nret = %d\n", ret); fflush(stdout);
 ret = ft_printf("{%-10%}");
 printf("\nret = %d\n", ret); fflush(stdout);
 ret = printf("{%-10%}"); fflush(stdout);
 printf("\nret = %d\n", ret); fflush(stdout);



 ft_printf("\n% Zoooo");
 ft_printf("\n%");
 ft_printf("\n{%}");
  printf("\n{% %}");
  printf("\n% Zoooo");
  printf("\n%");
  printf("\n{%}");

*/
}
