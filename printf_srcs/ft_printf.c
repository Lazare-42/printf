/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:08:31 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/28 22:08:18 by lazrossi         ###   ########.fr       */
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

void		apply_precision_width(t_printf *argument)
{
	if (argument->precision != -1)
		 apply_precision(argument);
	if (argument->show_sign || set_get_put_sign_back(0))
		 apply_plus_minus_flags(argument);
	if (argument->left_align_output != -1)
		 apply_flag_padding(argument);
	if (argument->width)
		 apply_width(argument);
	if (argument->sharp && ft_strchr("xoX", argument->type))
		 apply_sharp(argument);
}

char 	*treat_and_store_argument(va_list ap, t_printf *argument, char *format)
{
	format = get_flags(argument, format);
	format = get_width(ap, argument, format);
	format = get_precision(ap, argument, format);
	format = get_modifier(argument, format);
	store_type_data(ap, argument);
	if (argument->arg[0] == '0' && ft_strchr("oXx", argument->type))
			argument->sharp = 0;
	if (set_get_flags_presence(0) || (*argument).width ||
			(*argument).precision > -1)
		apply_precision_width(argument);
	return (format);
}

const char	*store_string(const char *format, t_printf *argument)
{
	while (*format && (*format != '%' || (*format == '%' &&
			((*(1 + format) == '%' ) || !(*(1 + format))))))
	{
		if (*format == '%' && (*(1 + format) == '%'))
			format++;
		(*argument).before[set_get_before_len(1)] = *format;
		format++;
	}
	return (format);
}

void	parse(const char *format, va_list ap, t_printf *argument)
{
	format = store_string(format, argument);
	if (*format && *format == '%' && *(1 + format) && *(1 + format) != '%')
		format = treat_and_store_argument(ap, argument, (char*)++format);
	if (*format && set_get_return(0) != -1)
	{
		print_flush(*argument);
		*argument = initialize_elem();
		parse(format, ap, argument);
	}
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_printf	argument;

	argument = initialize_elem();
	if (!(format))
	{
		ft_putstr_fd("Please stop fooling around with my ft_printf.", 2);
		return (-1);
	}
	va_start(ap, format);
	parse(format, ap, &argument);
	va_end(ap);
	if ((set_get_return(0) > -1))
	{
		print_flush(argument);
		return (set_get_return(0));
	}
	else
		return (-1);
}
