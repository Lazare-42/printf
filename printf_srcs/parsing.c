/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 00:14:26 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/19 19:46:23 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

static const char	*store_string(const char *format, t_printf *argument_specs, t_str *argument_str)
{
	while (format && *format && *format != '%')
	{
		if (*format == '[' && *(1 + format) && *(1 + format) == '[')
			format = terminal_formatting(format, argument_str);
		if (format && *format && *format != '%')
		{
			argument_str->str[argument_str->position++] = *format;
			format++;
		}
	}
	if (format && *format == '%')
	{
		argument_specs->percentage_presence = 1;
		format++;
	}
	return (format);
}

void						get_type(t_printf *argument, const char *format)
{
	if (*format == 'i')
		argument->type = 'd';
	else
		argument->type = *format;
	if (*format == 'p')
		argument->sharp = 1;
	if (argument->show_sign && ft_strchr("xXpc", *format))
		argument->show_sign = 0;
	else if (ft_strchr("xX", argument->type) && argument->sharp
			&& argument->width > 1)
		argument->width--;
}

const char			*parse(const char *format, t_printf *argument, t_str *argument_str, va_list ap)
{
	int tmp;

	tmp = 1;
	format = store_string(format, argument, argument_str);
	while (format && *format && tmp)
	{
		tmp = 0;
		if (ft_strchr("sSpdDioOuUxXcCeEfFgGaAnb", *format))
		{
			get_type(argument, format);
			format++;
		}
		else if (ft_strchr("-0+ #", *format)
				&& (tmp = get_flags(argument, format)))
			format += tmp;
		else if ((ft_isdigit(*format) || *format == '*')
				&& !argument->precision
				&& (tmp = get_width(ap, argument, format)))
			format += tmp;
		else if (*format == '.' && (tmp = get_precision(ap, argument, format)))
			format += tmp;
		else if (format && ft_strchr("hhljz", *format))
			if ((tmp = get_modifier(argument, format)))
				format += tmp;
	}
	if (!argument->type && format && *format)
		argument_str->str[argument_str->position++] = *format++;
	return (format);
}
