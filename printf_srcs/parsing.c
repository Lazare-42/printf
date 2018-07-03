/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:14:26 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/03 01:06:40 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

char	*store_string(char *format, t_printf *argument)
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

char	*parse(char *format, t_printf *argument, va_list ap)
{
	format = store_string(format, argument);
	get_precision(ap, argument, ft_strstrchr(format, ".", '%'));
	get_width(ap, argument, ft_strstrchr(format, "123456789", '.'));
	get_width(ap, argument, ft_strstrchr(format, "*", '.'));
	get_flags(argument, ft_strstrchr(format, "-0+ #",'%'));
	get_modifier(argument, ft_strstrchr(format,"sSpdDioOuUxXcCeEfFgGaAnhhljz", '%'));
	if (ft_strstrchr(format, "%", '\0'))
	{
		format = ft_strstrchr(format, "%", '\0');
		if (argument->type == '0' && *format == '%')
		{
			argument->to_store = (void*)format;
			store_print_handler(argument, 1, 1, 1);
			format++;
		}
	}
	else if (argument->type == '0' && argument->percentage_presence)
	{
		argument->to_store = (void*)&format[ft_strlen(format) - 1];
		store_print_handler(argument, 1, 1, 1);
		return (NULL);
	}
	else if (argument->type != '0')
		format = ft_strstrchr(format, "sSpdDioOuUxXcCeEfFgGaAn", 0) + 1;
	return (format);
}
