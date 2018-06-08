#include "../libft/includes/libft.h"
#include "../includes/printf.h"

/* 
 ** flag - which left aligns output and flag 0 which prepends 0 in front
 ** both use same element of the structure left_align_output as they cannot  
 ** coexist. Default left_align_output is -1
 */
char	*get_flags(t_printf **argument, char *format)
{
	while (*format == '-' || *format == '0' || *format == '+' || *format == ' '
			|| *format == '#')
	{
		if (*format == '-')
			(*argument)->left_align_output = 1;
		if (*format == '0')
			(*argument)->left_align_output = 0;
		if (*format == '+')
			(*argument)->show_sign = 1;
		if (*format == ' ')
			(*argument)->show_sign = ' ';
		if (*format == '#')
			(*argument)->sharp = 1;
		format++;
	}
	return (format);
}
