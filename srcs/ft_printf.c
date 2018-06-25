#include "printf.h"
#include "../libft/includes/libft.h"

/*
 ** the fonction parse stores the string argument 
 ** in a string in a structure of a linked list.
 ** If it meets an argument it
 ** sends the structure and the va_list element
 ** to the function treat_and_store elements
 ** return of ft_printf is defined and found in set_get_return() 
 */

char	*store_string(char *format, char **print_str)
{
	while (*format && (*format != '%' || (*format == '%' &&
					*(1 + format) == '%')))
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

void	parse(char *format, va_list ap)
{
	t_printf	*argument;

	argument = NULL;
	if (!(argument = set_get_arg_list(0)))
	{
		set_get_return((-1));
		return ;
	}
	format = store_string(format, &(argument->before));
	if (*format && *format == '%' && *(1 + format) && *(1 + format) != '%')
		format = treat_and_store_argument(ap, &argument, (char*)++format);
	if (*format && set_get_return(0) != -1)
		parse(format, ap);
}


int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	char		*format_cpy;

	format_cpy = NULL;
	if (!(format))
	{
		ft_putstr_fd("Please stop fooling around with my ft_printf.", 2);
		return (-1);
	}
	if (!(format_cpy = ft_strdup(format)))
		return (-1);
	va_start(ap, format);
	parse(format_cpy, ap);
	va_end(ap);
	if ((set_get_return(0) > -1))
		return (print_list());
	else
		return (-1);
}
