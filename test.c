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


  /*
	ret = ft_printf("%0+5d", 42);
	ret = ft_printf("%+010.4d", 0);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%0+5d", 42);
	ret = printf("%+010.4d", 0);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = ft_printf("toto%.0d et %+.d", 0, 1);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("toto%.0d et %+.d", 0, 1);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = ft_printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	printf("\nret = %d\n", ret); fflush(stdout);
	
	ret = ft_printf("coco et %-#-#--24O titi%#012o", 12, -874);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("coco et %-#-#--24O titi%#012o", 12, -874);
	printf("\nret = %d\n", ret); fflush(stdout);

	ret = ft_printf("\n%024hho et%#1.2o %0012.O", (unsigned char)12, 0, 123654789);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("\n%024hho et%#1.2o %0012.O", (unsigned char)12, 0, 123654789);
	printf("\nret = %d\n", ret); fflush(stdout);

	ret = ft_printf("%#08x", 42);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%#08x", 42);
	printf("\nret = %d\n", ret); fflush(stdout);

	ret = ft_printf("%0#15.0o", 12587499);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%0#15.0o", 12587499);
	printf("\nret = %d\n", ret); fflush(stdout);

	ret = ft_printf("%05o", 42);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%05o", 42);
	printf("\nret = %d\n", ret); fflush(stdout);
   * 
	ret = ft_printf("%92p", 0);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%92p", 0);
	printf("\nret = %d\n", ret); fflush(stdout);

	ret = ft_printf("%#8o", 42);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%#8o", 42);
	printf("\nret = %d\n", ret); fflush(stdout);
	
	ret = ft_printf("%#8x", 42);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%#8x", 42);
	printf("\nret = %d\n", ret); fflush(stdout);

	ret = ft_printf("%#4x", 0);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%#4x", 0);
	printf("\nret = %d\n", ret); fflush(stdout);

	ret = ft_printf("%0#10.0x %0#x", 12345, 0);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%0#10.0x %0#x", 12345, 0);
  */
	ret = ft_printf("%0#10.0x", 0);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("%0#10.0x", 0);
	printf("\nret = %d\n", ret); fflush(stdout);
	/*
	*/

}
