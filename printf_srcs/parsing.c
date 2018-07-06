/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:14:26 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/06 04:30:11 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

char	*store_string(char *format, t_printf *argument)
{
	while (*format && !ft_strchr("*%", *format))
	{
		argument->to_store = (void*)format;
		store_print_handler(argument, 1, 0, 1);
		format++;
	}
	if (*format == '%' || (*format == '*' && *(1 + format) && ft_strchr(".#.123456789sSpdDioOuUxXcCeEfFgGaAnhhljz", *(1 + format))))
	{
		argument->percentage_presence = 1;
		format++;
	}
	return (format);
}

char	*parse(char *format, t_printf *argument, va_list ap)
{
	format = store_string(format, argument);
	get_precision(ap, argument, ft_strstrchr(format, ".", '%'));
	get_width(ap, argument, ft_strstrstr(format, "123456789", ".%sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	get_width(ap, argument, ft_strstrstr(format, "*", ".%sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	get_modifier(argument, ft_strstr_whilestr(format,"sSpdDioOuUxXcCeEfFgGaAnhhljz", "-0+ #.123456789sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	get_flags(argument, ft_strstrstr(format, "-0+ #",".%123456789sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	if (ft_strstrchr(format, "%", '\0') && argument->type == '0')
	{
		format = ft_strstrchr(format, "%", '\0');
		if (argument->type == '0' && *format == '%')
		{
			argument->to_store = (void*)format;
			store_print_handler(argument, 3, 1, 1);
			format++;
		}
	}
	else if (argument->type == '0' && argument->percentage_presence)
	{
		while (*format && ft_strchr("-0+ #.123456789sSpdDioOuUxXcCeEfFgGaAnhhljz", *format))
			format++;
		if (*format && argument->type == '0' && *format != '%')
		{
			argument->to_store = (void*)format;
			store_print_handler(argument, 3, 1, 1);
			format++;
		}
	}
	else if (argument->type != '0')
		format = ft_strstrchr(format, "sSpdDioOuUxXcCeEfFgGaAn", 0) + 1;
	return (format);
}
