/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_and_store_argument.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:30:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/06 03:27:40 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"
#include <stdarg.h>

/* 
 ** treat_and_store_argument first sends to the function get_flags
 ** Where it stores width and precision either statically or dynamically via a
 ** call to va_list ap
 ** it checks for an optional length modifier and stores the type in
 ** store_modifier
 ** Finally it stores the type data according to type and modifier in
 ** store_type_data
 **
 */

static int	type_to_int_base(char type)
{
	if (ft_strchr("oO", type))
		return (8);
	else if (ft_strchr("uUdiD", type))
		return (10);
	else
		return (16);
}

t_printf	treat_store_modifier_u_data(va_list ap, t_printf argument)
{
	if (ft_strchr("ouxX", argument.type))
	{
		if (!(ft_strcmp("hh", argument.modifier)))
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, unsigned int), sizeof(unsigned char), &argument);
		else if (*argument.modifier == 'h')
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, unsigned int), sizeof(unsigned short), &argument);
		else if (*argument.modifier == 'l')
		{
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, unsigned long), sizeof(unsigned long), &argument);
		}
		else if (!(ft_strcmp("ll", argument.modifier)))
		{
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, unsigned long long), sizeof(unsigned long long),
					&argument);
		}
		else if (*argument.modifier == 'j')
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, uintmax_t), sizeof(uintmax_t), &argument);
		else if (*argument.modifier == 'z')
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, size_t), sizeof(size_t), &argument);
	}
	return (argument);
}

t_printf	treat_store_modifier_s_data(va_list ap, t_printf argument)
{
	if (ft_strchr("di", argument.type))
	{
		if (!(ft_strcmp("hh", argument.modifier)))
			printf_s_base_converter(type_to_int_base(argument.type),
					va_arg(ap, int), sizeof(signed char), &argument);
		else if (*argument.modifier == 'h')
			printf_s_base_converter(type_to_int_base(argument.type),
					va_arg(ap, int), sizeof(short), &argument);
		if (!(ft_strcmp("ll", argument.modifier)))
			printf_s_base_converter(type_to_int_base(argument.type),
					va_arg(ap, long long), sizeof(long long),
					&argument);
		else if (*argument.modifier == 'l')
			printf_s_base_converter(type_to_int_base(argument.type),
					va_arg(ap, long), sizeof(long), &argument);
		else if (*argument.modifier == 'j')
			printf_s_base_converter(type_to_int_base(argument.type),
					va_arg(ap, intmax_t), sizeof(intmax_t), &argument);
		else if (*argument.modifier == 'z')
			printf_s_base_converter(type_to_int_base(argument.type),
					va_arg(ap, size_t), sizeof(size_t), &argument);
	}
	return (argument);
}


void		store_type_data(va_list ap, t_printf *argument)
{
	char	*va_arg_str;

	va_arg_str = NULL;
	if ((ft_strchr("ouxX", (*argument).type)) && ((*argument->modifier)))
		*argument = treat_store_modifier_u_data(ap, *argument);
	else if (ft_strchr("ouxX", (*argument).type))
		printf_u_base_converter(type_to_int_base((*argument).type),
				va_arg(ap, int), sizeof(int), argument);
	else if (ft_strchr("di", (*argument).type))
	{
		if (!((*argument->modifier)))
			printf_s_base_converter(type_to_int_base((*argument).type),
					va_arg(ap, int), sizeof(int), argument);
		else 
			*argument = treat_store_modifier_s_data(ap, *argument);
	}
	else if (ft_strchr("OU", (*argument).type))
		printf_u_base_converter(type_to_int_base((*argument).type),
				va_arg(ap, long int), sizeof(long int), argument);
	else if (argument->type == 'D')
		printf_s_base_converter(type_to_int_base((*argument).type),
				va_arg(ap, long int), sizeof(long int), argument);
	else if ((*argument).type == 'c' && !*argument->modifier)
	{
		char c;

		c = va_arg(ap, int);
		argument->to_store = (void*)&c;
		store_print_handler(argument, 3, sizeof(char), 1);
	}
	else if ((*argument).type == 's' && !*argument->modifier)
	{
		if (argument->precision < 0)
			return ;
		va_arg_str = va_arg(ap, char *);
		if (!va_arg_str)
		{
			argument->to_store = (void*)"(null)";
			store_print_handler(argument, 2, 1, 6);
			return ;
		}
		argument->to_store = (void*)va_arg_str;
		if (argument->precision > 0 && argument->precision < (int)ft_strlen(va_arg_str))
		{
			store_print_handler(argument, 3, 1, argument->precision);
		}
		else
			store_print_handler(argument, 3, 1, ft_strlen(va_arg_str));
	}
	else if (argument->type == 'C' || (argument->type == 'c' && *argument->modifier == 'l'))
		store_unicode(va_arg(ap, wint_t), argument, 4);
	else if (argument->type == 'S' || (argument->type == 's' && *argument->modifier == 'l'))
		store_unicode_str(va_arg(ap, wchar_t*), argument);
	if ((*argument).type == 'p')
		get_hex_ptr_adr(ap, argument);
}
