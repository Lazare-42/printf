#include "../libft/includes/libft.h"
#include "../includes/printf.h"

/* 
 ** flag - which left aligns output and flag 0 which prepends 0 in front
 ** both use same element of the structure left_align_output as they cannot  
 ** coexist. Default left_align_output is -1
 */

char	*get_precision(va_list ap, t_printf **argument, char *format)
{
	if (*format && *format == '.')
	{
		format++;
		if (*format && *format != '*' && !(ft_isdigit(*format)))
			(*argument)->precision = 0;
		else if (*format && ft_isdigit(*format))
		{
			(*argument)->precision = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
			if (((*argument)->malloc_precision_width))
				(*argument)->malloc_precision_width = 2;
			else
				(*argument)->malloc_precision_width = 1;
		}
		else if (*format == '*' && format++)
			(*argument)->precision = va_arg(ap, int);
	}
	return (format);
}

char	*get_width(va_list ap, t_printf **argument, char *format)
{
	if (ft_isdigit(*format))
	{
		(*argument)->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
		(*argument)->malloc_precision_width = 1;
	}
	else if (*format == '*' && format++)
		(*argument)->width = va_arg(ap, int);
	return (format);
}

char	*get_flags(t_printf **argument, char *format)
{
	while (*format == '-' || *format == '0' || *format == '+' || *format == ' '
			|| *format == '#')
	{
		set_get_flags_presence(1);
		if (*format == '-')
			(*argument)->left_align_output = 1;
		if (*format == '0')
			(*argument)->left_align_output = 0;
		if (*format == '+' && (*argument)->show_sign != '+')
			(*argument)->show_sign = '+';
		if (*format == ' ')
			(*argument)->show_sign = ' ';
		if (*format == '#')
			(*argument)->sharp = 1;
		format++;
	}
	return (format);
}
