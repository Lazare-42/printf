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

#include <math.h>

int main()
{
	setlocale(LC_ALL, "");

	int ret;

int test = 420;

(void)test;


	ret = ft_printf("%s\n", "coco", NULL, "yooo");
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%s\n", "coco", NULL, "yooo");
	printf("\nret = %d\n", ret); fflush(stdout);

/*
ret =   ft_printf("%-15x", 542);
ret =   ft_printf("%2x", 542);
ret =   ft_printf("%.2x", 5427);
	ret = ft_printf("toto%.0d et %+.d", 0, 1);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("toto%.0d et %+.d", 0, 1);
	printf("\nret = %d\n", ret); fflush(stdout);
   * 
	ret = ft_printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	ret = ft_printf("coco et %-#-#--24O titi%#012o", 12, -874);
	ret = ft_printf("\n%024hho et%#1.2o %0012.O", (unsigned char)12, 0, 123654789);
	ret = ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	ret = ft_printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
	ret = ft_printf("%0#10.0x %0#x", 12345, 0);
	ret = ft_printf("%0#10.0x", 0);
  */

}
