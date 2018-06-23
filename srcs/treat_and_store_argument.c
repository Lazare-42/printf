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

char		*int_type(char type, uintmax_t value, int sizeof_var)
{
	char	*arg;

	arg = NULL;
	if (ft_strchr("diD", type))
		arg = ft_ltoa(value);
	else
		arg = ft_u_base_converter(type_to_int_base(type), value, sizeof_var);
	return (arg);
}

char		*treat_store_modifier_data(char type, va_list ap, char *modifier)
{
	char	*arg;

	arg = NULL;
	if (ft_strchr("ouxX", type))
	{
		if (!(ft_strcmp("hh", modifier)))
			arg = ft_u_base_converter(type_to_int_base(type), va_arg(ap, unsigned int), sizeof(unsigned char));
		else if (*modifier == 'h')
			arg = ft_u_base_converter(type_to_int_base(type), va_arg(ap, unsigned int), sizeof(unsigned short));
		if (!(ft_strcmp("ll", modifier)))
			arg = ft_u_base_converter(type_to_int_base(type), va_arg(ap, unsigned long long), sizeof(unsigned long long));
		else if (*modifier == 'l')
			arg = ft_u_base_converter(type_to_int_base(type), va_arg(ap, unsigned long), sizeof(unsigned long));
		else if (*modifier == 'j')
			arg = ft_u_base_converter(type_to_int_base(type), va_arg(ap, uintmax_t), sizeof(uintmax_t));
		else if (*modifier == 'z')
			arg = ft_u_base_converter(type_to_int_base(type), va_arg(ap, size_t), sizeof(size_t));
	}
	/*
	else if (type == 'C' || *modifier == 'c')
		arg = va_arg(ap, wint_t);
	else if (type == 'S' || * modifier == 's')
		arg = va_arg(ap, wchar_t);
		*/
	return (arg);
}

t_printf	*store_type_data(va_list ap, t_printf *argument)
{
	// but wait this *if* should be one function below
	if ((ft_strchr("ouxXcs", (argument)->type)) && (*((argument)->modifier) || (argument)->type == 'C' || (argument)->type == 'S'))
		(argument)->arg = treat_store_modifier_data((argument)->type, ap, (argument)->modifier);
	else
	{
		if (ft_strchr("diouxX", (argument)->type))
			(argument)->arg = int_type((argument)->type, va_arg(ap, int), sizeof(int));
		else if (ft_strchr("DOU", (argument)->type))
			(argument)->arg = int_type((argument)->type, va_arg(ap, long int), sizeof(long int));
		else if ((argument)->type == 'c')
			(argument)->arg = ft_strjoinfree_str_char(&(argument)->arg, (char)va_arg(ap, int));
		else if ((argument)->type == 's')
			(argument)->arg = ft_strdup(va_arg(ap, char *));
		else if ((argument)->type == 'p')
			(argument)->arg = get_hex_ptr_adr(ap, argument->precision);
	}
	if ((argument)->type == 'X' && ((argument)->arg))
		ft_mystriter(&((argument)->arg), ft_mins_to_caps);
	return (argument);
}

char	*store_modifier(t_printf **argument, char *format)
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
	return (format);
}

char 	*treat_and_store_argument(va_list ap, t_printf **argument, char *format)
{
	format = get_flags(argument, format);
	format = get_width(ap, argument, format);
	format = get_precision(ap, argument, format);
	format = store_modifier(argument, format);
	*argument = store_type_data(ap, *argument);
	if (set_get_flags_presence(0) || (*argument)->width || (*argument)->precision > -1)
		*argument = apply_precision_width(*argument);
	return (format);
}
