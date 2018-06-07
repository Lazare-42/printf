#include "../libft/includes/libft.h"
#include "../includes/printf.h"
#include <stdarg.h>

/* 
 ** treat_and_store_argument first sends to the function get_flags
 ** it then stores width and precision either statically or dynamically via a
 ** call to va_list ap
 */

char 	*treat_and_store_argument(va_list ap, t_printf **argument, char *format)
{
	format++;
	format = get_flags(argument, format);
	if (ft_isdigit(*format))
	{
		(*argument)->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	else if (*format == '*')
	{
		(*argument)->width = va_arg(ap, int);
		format++;
	}
	if (*format && *format == '.')
	{
		format++;
		if (*format && ft_isdigit(*format))
		{
			(*argument)->precision = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
		else if (*format == '*')
		{
			(*argument)->precision = va_arg(ap, int);
			format++;
		}
	}
	return (format);
}
