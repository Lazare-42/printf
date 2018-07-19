/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:08:31 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/19 20:52:15 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

#include "../includes/printf.h"
#include "../includes/libft.h"
#include <unistd.h>

static void		apply_precision_width(t_printf *argument)
{
	if (argument->sharp && ft_strchr("xoXp", argument->type)
			&& !argument->left_align_output)
		apply_sharp(argument);
	if (argument->show_sign && (argument->left_align_output == 1 || (argument->left_align_output == 0 && !argument->precision)))
		apply_plus_minus_flags(argument);
	if (argument->precision != -1 && argument->left_align_output == 1
			&& argument->type)
		apply_precision(argument);
	if (argument->width)
		apply_width(argument);
	if (argument->sharp && ft_strchr("xoXpO", argument->type)
			&& argument->left_align_output)
		apply_sharp(argument);
	if (argument->left_align_output == 1)
		apply_flag_padding(argument);
	if (argument->show_sign && (argument->left_align_output == -1  || (!argument->left_align_output && argument->precision)))
		apply_plus_minus_flags(argument);
	if (argument->precision > 0 && argument->left_align_output <= 0
			&& argument->type)
		apply_precision(argument);
}

static void		treat_and_store_argument(va_list ap, t_printf *argument)
{
	if (ft_strchr("ouxXdiOUDb", argument->type))
		store_number_data(ap, argument);
	else
		store_char_data(ap, argument);
}

static t_printf	initialize_elem(void)
{
	t_printf argument;

	argument.type = 0;
	ft_memset(argument.modifier, 0, 3);
	ft_memset(argument.sign, 0, 3);
	argument.arg_len = 0;
	argument.width = 0;
	argument.sharp = 0;
	argument.precision = 1;
	argument.show_sign = 0;
	argument.percentage_presence = 0;
	argument.left_align_output = -1;

	return (argument);
}

static int		parsing_handler(const char *format, va_list ap)
{
	t_printf	argument_specs;
	t_str		argument_str;
	va_list		copy;

	while (format && *format)
	{
		argument_specs = initialize_elem();
		format = parse(format, &argument_specs, &argument_str, ap);
		if (argument_specs.width ||
				argument_specs.precision > -1 || argument_specs.sharp)
		{
			va_copy(copy, ap);
			if (ft_strchr("ouxXdiOUDb", argument_specs.type))
				argument_specs.arg_len = get_number_len(ap, &argument_specs);
			else
				argument_specs.arg_len = get_char_len(ap, &argument_specs);
			apply_precision_width(&argument_specs);
		}
		if (argument_specs.type)
			treat_and_store_argument(ap, &argument_specs);
	}
	return (write(1, &argument_str.str, argument_str.position));
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			return_val;

	return_val = -1;
	if (!(format))
	{
		ft_putstr_fd("Please stop fooling around with my ft_printf.", 2);
		return (-1);
	}
	va_start(ap, format);
	return_val = parsing_handler(format, ap);
	va_end(ap);
	store_print_handler(NULL, 0, 0, 0);
	return (return_val);
}
