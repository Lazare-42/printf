/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_and_store_argument.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:30:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/26 23:31:42 by lazrossi         ###   ########.fr       */
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
** in function treat_store_modifier_data
** else if (type == 'C' || *modifier == 'c')
** arg = va_arg(ap, wint_t);
** else if (type == 'S' || * modifier == 's')
** arg = va_arg(ap, wchar_t);
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

t_printf	treat_store_modifier_data(va_list ap, t_printf argument)
{
	if (ft_strchr("ouxX", argument.type))
	{
		if (!(ft_strcmp("hh", argument.modifier)))
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, unsigned int), sizeof(unsigned char), &argument);
		else if (*argument.modifier == 'h')
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, unsigned int), sizeof(unsigned short), &argument);
		if (!(ft_strcmp("ll", argument.modifier)))
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, unsigned long long), sizeof(unsigned long long),
					&argument);
		else if (*argument.modifier == 'l')
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, unsigned long), sizeof(unsigned long), &argument);
		else if (*argument.modifier == 'j')
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, uintmax_t), sizeof(uintmax_t), &argument);
		else if (*argument.modifier == 'z')
			printf_u_base_converter(type_to_int_base(argument.type),
					va_arg(ap, size_t), sizeof(size_t), &argument);
	}
	return (argument);
}

void		store_type_data(va_list ap, t_printf *argument)
{
	char	*va_arg_str;

	va_arg_str = NULL;
	if ((ft_strchr("ouxXcs", (*argument).type)) && ((*(*argument).modifier) || (*argument).type == 'C' || (*argument).type == 'S'))
		*argument = treat_store_modifier_data(ap, *argument);

	else if (ft_strchr("diouxX", (*argument).type))
			printf_u_base_converter(type_to_int_base((*argument).type),
					va_arg(ap, int), sizeof(int), argument);
	else if (ft_strchr("DOU", (*argument).type))
			printf_u_base_converter(type_to_int_base((*argument).type),
					va_arg(ap, long int), sizeof(long int), argument);
	else if ((*argument).type == 'c' && !*(*argument).arg)
		(*argument).arg[set_get_arg_len(1)] = (char)va_arg(ap, int);

	else if ((*argument).type == 's')
	{
		// Alright so we have a huge problem here : to avoid mallocing we want
		// to print this string as soon as we receive it
		// but it still needs to get formatted according to precision and width
		// so.... How should I do ?
		// 1. If there is no precision or width set ; you can directly print
		// 2. Else you need to apply the parsing
		// j
		// I built up the function precision to directly accomodate this case
		// However this disrupts the handler function I directly had in ft_printf
		va_arg_str = va_arg(ap, char *);
		if (!va_arg_str)
			stack_str_fill(argument, "null");
	}
	else if ((argument).type == 'p')
		(argument).arg = get_hex_ptr_adr(ap, argument.precision);
	if ((argument).type == 'X' && ((argument).arg))
		ft_mystriter(&((argument).arg), ft_mins_to_caps);
	return (argument);
}

