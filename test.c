#include <stdio.h>
#include "includes/libft.h"
#include "includes/printf.h"
#include <stdlib.h>
#include <limits.h>
#include <locale.h>

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
	setlocale(LC_ALL, "");

	int ret;

 ret =  ft_printf("\n%#6x", 2500);
	printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("\n%#6x", 2500);
	printf("\nret = %d\n", ret); fflush(stdout);
	/*
 ret =  ft_printf("\n%-#6o", 2500);
	printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("\n%#8x", 42);
	printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("\n%#08x", 42);
	printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("\n%#6o", 2500);

	ret = ft_printf("{%*3d}", 0, 0);
	ret = printf("{%*3d}", 0);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = ft_printf("%#o", 0);
	ret = printf("%#o", 0);
printf("\nret = %d\n", ret); fflush(stdout);
	ret = ft_printf("%#.o, %#.0o", 0, 0);
printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%#.o, %#.0o", 0, 0);
printf("\nret = %d\n", ret); fflush(stdout);
	ret = ft_printf("{%05s}", "abc");
printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("{%05s}", "abc");
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
