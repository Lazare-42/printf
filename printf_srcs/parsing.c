/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:14:26 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 16:42:35 by lazrossi         ###   ########.fr       */
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

static	char	*type_0_modifications(char *format, t_printf *argument)
{
	if (ft_strstrchr(format, "%", '\0'))
	{
		format = ft_strstrchr(format, "%", '\0');
		if (argument->type == '0' && *format == '%')
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
		if (*format && argument->type == '0' && *format != '%')
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
	format = store_string(format, argument);
	get_modifier(argument,
		ft_strstr_whilestr(format, "sSpdDioOuUxXcCeEfFgGaAnhhljz",
			"*-0+ #.123456789sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	get_width(ap, argument,
		ft_strstrstr(format, "123456789", ".%sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	get_width(ap, argument,
		ft_strstrstr(format, "*", ".%sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	get_precision(ap, argument,
		ft_strstrstr(format, ".", "%sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	get_flags(argument,
		ft_strstrstr(format,
			"-0+ #", ".%123456789sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	if (argument->type == '0')
		format = type_0_modifications(format, argument);
	else if (ft_strchr("xX", argument->type) && argument->sharp
			&& argument->width > 1)
		argument->width--;
	if (argument->type != '0')
		format = ft_strstrchr(format, "sSpdDioOuUxXcCeEfFgGaAn", 0) + 1;
	return (format);
}
