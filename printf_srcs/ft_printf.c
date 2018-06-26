/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:08:31 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/26 16:58:01 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "../includes/libft.h"

/*
** the fonction parse stores the string argument
** in a string in a structure of a linked list.
** If it meets an argument it
** sends the structure and the va_list element
** to the function treat_and_store elements which stores all required elements
** (width, precision, argument itself) in the structure and eventually sends
** the structure and its element to the precision and width handler, 
** apply_precision_width
** If any error is encoutered set_get_return is set to -1. Else the function
** ft_printf returns from the write function in print_list()
*/

t_printf		*apply_precision_width(t_printf *argument)
{
	if (argument->show_sign)
		argument = apply_plus_minus_flags(argument);
	if (argument->sharp && ft_strchr("xoX", argument->type))
		argument = apply_sharp(argument);
	if (argument->precision != -1)
		argument = apply_precision(argument);
	if (argument->left_align_output != -1)
		argument = apply_flag_padding(argument);
	if (argument->width)
		argument = apply_width(argument);
	return (argument);
}

char 	*treat_and_store_argument(va_list ap, t_printf argument, char *format)
{
	format = get_flags(&argument, format);
	format = get_width(ap, &argument, format);
	format = get_precision(ap, &argument, format);
	format = get_modifier(&argument, format);
	argument = store_type_data(ap, &argument);
	if (set_get_flags_presence(0) || (*argument)->width ||
			*argument.precision > -1)
	{
		*argument = apply_precision_width(*argument);
	}
	return (format);
}

char	*store_string(char *format, t_printf *argument)
{
	while (*format && (*format != '%' || (*format == '%' &&
					((*(1 + format) == '%' ) || !(*(1 + format))))))
	{
		if (*format && *format == '%' && (*(1 + format) == '%'))
		{
			(*argument).[set_get_printf_len(0)] = '%';
			set_get_tmp_len(1);
			format += 2;
		}
		g_printf_str[set_get_printf_len(0)] = '%';
		set_get_tmp_len(1);
		format++;
	}
	return (format);
}

void	parse(char *format, va_list ap)
{
	t_printf	argument;

	argument = set_get_arg_list();
	format = store_string(format, &argument);
	if (*format && *format == '%' && *(1 + format) && *(1 + format) != '%')
		format = treat_and_store_argument(ap, &argument, (char*)++format);
	if (*format && set_get_return(0) != -1)
		parse(format, ap);
}

int		ft_printf(const char *restrict format, ...)
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
	ft_memdel((void**)&format_cpy);
	if ((set_get_return(0) > -1))
		return (print_list());
	else
		return (-1);
}
