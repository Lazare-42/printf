/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:14:26 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/03 19:54:25 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

char	*store_string(char *format, t_printf *argument)
{
	char *tmp;

	tmp = format;
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

char	*parse(char *format, t_printf *argument, va_list ap)
{
	format = store_string(format, argument);
	if (!argument->percentage_presence)
		get_precision(ap, argument, ft_strstrchr(format, ".", '%'));
	get_width(ap, argument, ft_strstrstr(format, "123456789", ".%sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	get_width(ap, argument, ft_strstrstr(format, "*", ".%sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	if (argument->type != '0')
		get_flags(argument, ft_strstrstr(format, "-0+ #",".%123456789sSpdDioOuUxXcCeEfFgGaAnhhljz"));
	get_modifier(argument, ft_strstr_whilestr(format,"sSpdDioOuUxXcCeEfFgGaAnhhljz", ".*0123456789- + #"));



	format = ft_strdiff(format, ' ', ft_strlen(format));
	ft_putstr(format);
	if (argument->type == '0' && *format == '%')
	{
			argument->to_store = (void*)format;
			store_print_handler(argument, 3, 1, 1);
			format++;
	}
	else if (argument->type == '0' && argument->percentage_presence)
	{
		argument->to_store = (void*)format;
		store_print_handler(argument, 1, 1, 1);
	}
	else if (argument->type != '0')
		format = ft_strstrchr(format, "sSpdDioOuUxXcCeEfFgGaAn", 0) + 1;
	debug();
	return (format);
}
