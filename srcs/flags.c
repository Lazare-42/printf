#include "../libft/includes/libft.h"
#include "../includes/printf.h"

char	*get_flags(t_printf **argument, char *format)
{
	if (*format == '-')
	{
		(*argument)->left_align_output = 1;
		format++;
	}
	if (*format == '0')
	{
		(*argument)->width_type = '0';
		format++;
	}	
	if (*format == '+')
	{
		(*argument)->show_sign = 1;
		format++;
	}
	else if (*format == ' ' && !((*argument)->show_sign == 1))
	{
		(*argument)->show_sign = ' ';
		format++;
	}
	return (format);
}
