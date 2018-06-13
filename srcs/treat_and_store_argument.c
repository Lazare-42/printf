#include "../libft/includes/libft.h"
#include "../includes/printf.h"
#include <stdarg.h>
#include <stdlib.h>

/* 
 ** treat_and_store_argument first sends to the function get_flags
 ** Where it stores width and precision either statically or dynamically via a
 ** call to va_list ap
 ** it checks for an optional length modifier and stores the type in 
 ** store_modifier
 ** Finally it stores the type data according to type and modifier in 
 ** store_type_data
 */

// in this funciton i passed value by value ; ie the structure has been copied 
// to the stack. I should check once printf is done if is faster to pass it by
// reference. Copying a large structure is slow but dereferencing requires one
// more memory read

static int	type_to_int_base(char type)
{
	if (ft_strchr("oO", type))
		return (8);
	else if (ft_strchr("uU", type))
		return (10);
	else
		return (16);
}

void		int_type(char type, long int value, char **string, int sizeof_var)
{
	char	*tmp;

	tmp = NULL;
	if (ft_strchr("diD", type))
		tmp = ft_ltoa(value);
	else
		tmp = ft_u_base_converter(type_to_int_base(type), value, sizeof_var);
	if (type == 'X')
		ft_mystriter(&tmp, ft_mins_to_caps);
	if (tmp)
		*string = ft_strjoinfree(string, &tmp, 'B');
}

t_printf	*store_type_data(va_list ap, t_printf *argument)
{
	// but wait this *if* should be one function below
	// of course not return argument but treat as if modifier was present
	if ((ft_strchr("diouxXcs", argument->type)) && (*(argument->modifier) || argument->type == 'C' || argument->type == 'S'))
		return (argument);
	else
	{
		if (ft_strchr("diouxX", argument->type))
			int_type(argument->type, va_arg(ap, int), &(argument->before), sizeof(int));
		else if (ft_strchr("DOU", argument->type))
			int_type(argument->type, va_arg(ap, long int), &(argument->before), sizeof(long int));
		else if (argument->type == 'c')
			argument->before = ft_strjoinfree_str_char(&(argument->before), va_arg(ap, int));
		else if (argument->type == 's')
			argument->before = ft_joinfree_heapstr_stackstr(&(argument->before), va_arg(ap, char *), 'b');
		else if (argument->type == 'p')
			get_hex_ptr_adr(ap, &(argument->before));
	}
	if (!(argument->before))
		return (NULL);
	else
	{
		ft_putstr(argument->before);
		return (argument);
	}
}

char	*store_modifier(va_list ap, t_printf **argument, char *format)
{
	if (!(ft_strchr("sSpdDioOuUxXcCeEfFgGaAn", *format)))
	{
		(*argument)->modifier[0] = *format;
		format++;
		if (!(ft_strchr("sSpdDioOuUxXcCeEfFgGaAn", *format)))
		{
			(*argument)->modifier[1] = *format;
			format++;
		}
	}
	(*argument)->type = *format;
	format++;
	*argument = store_type_data(ap, *argument);
	return (format);
}

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
	else if (*format == '*' && format++)
		(*argument)->width = va_arg(ap, int);
	if (*format && *format == '.')
	{
		format++;
		if (*format && ft_isdigit(*format))
		{
			(*argument)->precision = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
		else if (*format == '*' && format++)
			(*argument)->precision = va_arg(ap, int);
	}
	format = store_modifier(ap, argument, format);
	return (format);
}
