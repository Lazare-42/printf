/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:12:07 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/06 04:23:22 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

/*
 ** flag - which left aligns output and flag 0 which prepends 0 in front
 ** both use same element of the structure left_align_output as they cannot
 ** coexist. Default left_align_output is -1
			if (argument->precision == 0 && argument->type == 's')
				argument->precision = 0;
 */

char	*get_precision(va_list ap, t_printf *argument, char *format)
{
	int i;

	i = 0;
	if (format && format[i] && format[i] == '.')
	{
		i++;
		if (format[i] == '*' && format[i++])
		{
			argument->precision = va_arg(ap, int);
			if (argument->precision < 0)
			{
				argument->precision = 0;
				argument->left_align_output = 0;
			}
		}
		else if (format[i] && format[i] != '*' && (!(ft_isdigit(format[i]))
					|| format[i] == '0'))
			(*argument).precision = -1;
		else if (format[i] && ft_isdigit(format[i]))
		{
			argument->precision = ft_atoi(&format[i]);
			while (ft_isdigit(format[i]))
				i++;
		}
	}
	return (format);
}

char	*get_width(va_list ap, t_printf *argument, char *format)
{
	int i;

	i = 0;
	if (format && ft_isdigit(format[i]))
	{
		argument->width = ft_atoi(format);
		while (ft_isdigit(format[i]))
			i++;
	}
	else if (format && format[i] == '*' && format[i++])
		argument->width = va_arg(ap, int);
	if (argument->width < 0)
	{
		argument->width *= -1;
		argument->left_align_output = 1;
	}
	return (format);
}

char	*get_flags(t_printf *argument, char *format)
{
	int i;


	i = 0;
	while (format && (format[i] == '-' || format[i] == '0' || format[i] == '+' || format[i] == ' '
				|| format[i] == '#'))
	{
		if (format[i] == '-')
			argument->left_align_output = 1;
		if (format[i] == '0' && argument->left_align_output != 1)
			argument->left_align_output = 0;
		if (format[i] == ' ' && (*argument).show_sign != '+' && argument->type
				!= '0')
			argument->show_sign = ' ';
		if (format[i] == '+')
			argument->show_sign = '+';
		if (format[i] == '#')
			argument->sharp = 1;
		i++;
	}
	return (format);
}

char	*get_modifier(t_printf *argument, char *format)
{
	int i;

	i = 0;
	if (format && !(ft_strchr("sSpdDioOuUxXcCeEfFgGaAn", format[i])) && (*(1 + format))
			&& ft_strchr("hhljz", format[i]))
	{
		(*argument).modifier[0] = format[i++];
		if (!(ft_strchr("sSpdDioOuUxXcCeEfFgGaAn", format[i])))
		{
			(*argument).modifier[1] = format[i];
			i++;
		}
	}
	if ((format && ft_strchr("*sSpdDioOuUxXcCeEfFgGaAn", format[i])))
	{
		argument->type = format[i];
		if (format[i] == 'c' && argument->show_sign)
			argument->show_sign = 0;
		if (format[i] == 'p')
			argument->sharp = 1;
		i++;
	}
	return (format);
}
