har	char_type_add(char c)
{
	static char ret = 0;

	if (c)
		ret = c;
	return (ret);
}
#include "printf.h"
#include "../libft/includes/libft.h"
#include <stdarg.h>

int	parse(const char *restrict format, va_list ap)
{
	ft_putstr((char*)format);
	(void)ap;
	return (1);

}

int	ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = parse(format, ap);
	va_end(ap);
	return (1);
}
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
int	set_get_precision(int yes)
{
	static char answer = 0;

	if (yes)
		answer = 1;
	return (answer);
}
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
	*/
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
	printf("%.*d\n", 10, 20);
	printf("%.10d\n", 311);
	printf("%.10ld\n", sizeof(long));
	ft_printf("test coucou\n");
	ft_printf("test coucou\n");
}
#include "../libft/includes/libft.h"
#include "../includes/printf.h"

/*
 ** the function width_padding applies the padding according the its sign
 ** for numeral objects.
 ** As you might not know, if the sign is < 0, width padding comes afterwards
 ** the object, otherwise it comes before
*/

char	*width_padding(char *printf_str, int int_nbr)
{
	static char	direction = '+';
	char		*padding_str;

	padding_str = NULL;
	if (int_nbr < 0)
	{
		direction = '-';
		int_nbr *= -1;
	}
	if (!(padding_str = ft_strnew(int_nbr)))
		return (ft_put_error_return_null("malloc error", "width_padding"));
	padding_str = ft_memset((void*)padding_str, ' ', int_nbr);
	if (direction == '-')
	{
		if (!(printf_str = ft_strjoinfree(&printf_str, &padding_str, 'B')))
			return (ft_put_error_return_null("malloc error", "width_padding"));
		return (printf_str);
	}
	if (!(printf_str = ft_strjoinfree(&padding_str, &printf_str, 'B')))
		return (ft_put_error_return_null("malloc error", "width_padding"));
	return (printf_str);
}
