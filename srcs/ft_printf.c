#include "printf.h"
#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/*
 ** the fonction parse stores the string argument 
 ** in a string in a structure of a linked list.
 ** If it meets an argument it
 ** sends the structure and the va_list element
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

char	*store_string(char *format, char **print_str)
{
	while (*format && (*format != '%' || (*format == '%' && *(1 + format) == '%')))
	{
		if (*format && *format == '%' && *(1 + format) && *(1 + format) == '%')
		{
			if (!(*print_str = ft_strjoinfree_str_char
						(print_str, '%')))
			{
				set_get_return(-1);
				return (NULL);
			}
			format += 2;
		}
		if (!(*print_str = ft_strjoinfree_str_char(print_str, *format)))
		{
			set_get_return(-1);
			return (NULL);
		}
		format++;
	}
	return (format);
}

int			parse(char *format, va_list ap)
{
	t_printf	*argument;

	argument = NULL;
	if (!(argument = set_get_arg_list(0)))
		return (set_get_return((-1)));
	format = store_string(format, &(argument->before));
	if (*format && *format == '%' && *(1 + format) && *(1 + format) != '%')
		format = treat_and_store_argument(ap, &argument, (char*)format);
	if (*format)
		parse(format, ap);
	// you probably want to return from the print function itself instead of from here
	return (set_get_return(0));
}


void		print_list(void)
{
	t_printf	*argument;

	argument = NULL;
	if (!(argument = set_get_arg_list(1)))
		(set_get_return((-1)));
	while (argument)
	{
		if (argument->before)
		{
			ft_putstr(argument->before);
			ft_putchar('\n');
		}
		if (argument->show_sign)
		{
			ft_putchar(argument->show_sign);
			ft_putchar('\n');
		}
		if (argument->left_align_output)
		{
			ft_putnbr(argument->left_align_output);
			ft_putchar('\n');
		}
		if (argument->width)
		{
			ft_putnbr(argument->width);
			ft_putchar('\n');
		}
		if (argument->precision)
		{
			ft_putnbr(argument->precision);
			ft_putchar('\n');
		}
		if (argument->type)
		{
			write(1, &(argument->type), 1);
			ft_putchar('\n');
		}
		argument = argument->next;
	}
}

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	char		*format_cpy;

	format_cpy = NULL;
	if (!(format_cpy = ft_strdup(format)))
		return (-1);
	va_start(ap, format);
	parse(format_cpy, ap);
	va_end(ap);
	print_list();
	return (set_get_return(0));
}
