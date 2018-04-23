#include "printf.h"
#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <stdlib.h>

/*
 ** the fonction parse stores the string argument 
 ** in a string in a structure of a linked list.
 ** If it meets an argument it sends the structure and the va_list element
 ** to the function treat_and_store elements
 ** return of ft_printf is defined and found in set_get_return() 
 */

int			set_get_return(int value)
{
	static int return_val = 0;

	if (return_val == -1)
		return (-1);
	if (!value)
		return (return_val);
	if (value == -1)
		return_val = -1;
	else
		return_val += value;
	return (return_val);

}

int			parse(const char *restrict format, va_list ap)
{
	t_printf	*argument;

	argument = NULL;
	if (!(argument = set_get_arg_list(0)))
		return (set_get_return((-1)));
	format--;
	while (*(++format))
	{
		if (*format == '%' && *(1 + format) && *(1 + format) != '%')
		{
			format = ft_treat_and_store_argument(ap, &argument, format);
			if (*format && !(argument = set_get_arg_list(0)))
				return (set_get_return((-1)));
		}
		if (*format && *format == '%' && *(1 + format) && *(1 + format) == '%')
		{
			if (!(argument->before = ft_joinfree_heapstr_stackstr
						(&(argument->before), "%%", 'a')))
				return (set_get_return(-1));
			format += 2;
		}
		if (*format && !(argument->before = ft_strjoinfree_str_char(&(argument->before), *format)))
			return (set_get_return(-1));
	}
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;

	va_start(ap, format);
	parse(format, ap);
	va_end(ap);
	return (set_get_return(0));
}

