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

int main()
{
	int ret;
	/*
	if (ac != 2)
		return (0);
	ft_printf(av[1]);
	*/
	ret = ft_printf("[[yellow]] What a [[bold]][[underline]][[italic]]beautiful[[end]][[yellow]] printf !");
	printf("\n ret = %d\n", ret);
//	printf("[[red]]%.*d", 1000000, 1);
}
