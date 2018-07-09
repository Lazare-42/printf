/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:14:26 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 19:37:02 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

static char		*store_string(char *format, t_printf *argument)
{
	while (*format && *format != '%')
	{
		argument->to_store = (void*)format;
		store_print_handler(argument, 1, 0, 1);
		format++;
	}
	if (*format == '%')
	{
		argument->percentage_presence = 1;
		format++;
	}
	return (format);
}

char	*type_0_modifications(char *format, t_printf *argument)
{
	if (ft_strstrchr(format, "%", '\0'))
	{
		format = ft_strstrchr(format, "%", '\0');
		if (argument->type == 0 && *format == '%')
		{
			argument->to_store = (void*)format;
			store_print_handler(argument, 3, 1, 1);
			format++;
		}
	}
	else if (argument->percentage_presence)
	{
		while (*format && ft_strchr(
					"-0+ #.123456789sSpdDioOuUxXcCeEfFgGaAnhhljz", *format))
			format++;
		if (*format && !argument->type && *format != '%')
		{
			argument->to_store = (void*)format;
			store_print_handler(argument, 3, 1, 1);
			format++;
		}
	}
	return (format);
}

char			*parse(char *format, t_printf *argument, va_list ap)
{
	int tmp;
	int point;

	point  = 0;
	format = store_string(format, argument);
	while (*format && *format != '%')
	{
		tmp = 0;
		if (ft_strchr("-0+ #", *format))
		{
			if ((tmp = get_flags(argument, format)))
				format += tmp;
		}
		else if((ft_isdigit(*format) || *format == '*') && !point)
		{
			if ((tmp = get_width(ap, argument, format)))
				format += tmp;
		}
		else if (*format == '.')
		{
			point = 1;
			if ((tmp = get_precision(ap, argument, format)))
				format += tmp;
		}
		if (ft_strchr("sSpdDioOuUxXcCeEfFgGaAnhhljz", *format))
		{
			format  += get_modifier(argument, format);
			break ;
		}
		if (tmp == 0)
			break ;
	}
	if (!argument->type && format)
		format = type_0_modifications(format, argument);
	else if (ft_strchr("xX", argument->type) && argument->sharp
			&& argument->width > 1)
		argument->width--;
	return (format);
}
