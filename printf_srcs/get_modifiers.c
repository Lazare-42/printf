/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:12:07 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/03 00:55:03 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

/*
** flag - which left aligns output and flag 0 which prepends 0 in front
** both use same element of the structure left_align_output as they cannot
** coexist. Default left_align_output is -1
*/

char	*get_precision(va_list ap, t_printf *argument, char *format)
{
	if (format && *format && *format == '.')
	{
		format++;
		if (*format && *format != '*' && !(ft_isdigit(*format)))
			(*argument).precision = -1;
		else if (*format && ft_isdigit(*format))
		{
			(*argument).precision = ft_atoi(format);
			while (ft_isdigit(*format))
				format++;
		}
		else if (*format == '*' && format++)
			(*argument).precision = va_arg(ap, int);
	}
	return (format);
}

char	*get_width(va_list ap, t_printf *argument, char *format)
{
	if (format && ft_isdigit(*format))
	{
		argument->width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	else if (format && *format == '*' && format++)
		argument->width = va_arg(ap, int);
	return (format);
}

char	*get_flags(t_printf *argument, char *format)
{
	while (format && (*format == '-' || *format == '0' || *format == '+' || *format == ' '
			|| *format == '#'))
	{
		if (*format == '-')
			argument->left_align_output = 1;
		if (*format == '0' && argument->left_align_output != 1)
			argument->left_align_output = 0;
		if (*format == ' ' && (*argument).show_sign != '+')
			argument->show_sign = ' ';
		if (*format == '+')
			argument->show_sign = '+';
		if (*format == '#')
			argument->sharp = 1;
		format++;
	}
	return (format);
}

char	*get_modifier(t_printf *argument, char *format)
{
	if (format && !(ft_strchr("sSpdDioOuUxXcCeEfFgGaAn", *format)) && (*(1 + format))
			&& ft_strchr("hhljz", *format))
	{
		(*argument).modifier[0] = *format;
		if (!(ft_strchr("sSpdDioOuUxXcCeEfFgGaAn", *format)))
		{
			(*argument).modifier[1] = *format;
			format++;
		}
	}
	if ((format && ft_strchr("sSpdDioOuUxXcCeEfFgGaAn", *format)))
	{
		argument->type = *format;
		if (*format == 'c' && argument->show_sign)
			argument->show_sign = 0;
		format++;
	}
	return (format);
}
