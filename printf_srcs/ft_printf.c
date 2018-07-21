/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:08:31 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/19 22:40:34 by lazrossi         ###   ########.fr       */
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

static void		treat_and_store_argument(va_list ap, t_printf *argument_specs, t_str *argument_str)
{
	argument_specs->argument_str = argument_str;
	if (ft_strchr("ouxXdiOUDb", argument_specs->type))
		store_number_data(ap, argument_specs);
	else
		store_char_data(ap, argument_specs,  argument_str);
}

static void		adjust_width_precision_for_sign(t_printf *argument_specs)
{
	if (argument_specs->arg_len >= argument_specs->width
		&& argument_specs->arg_len >= argument_specs->precision)
		return ;
	if (argument_specs->precision > argument_specs->width
			&& argument_specs->precision
			> 1)
		argument_specs->precision--;
	else if (argument_specs->width > argument_specs->precision)
		argument_specs->width--;
}

static void		apply_precision_width(t_printf *argument_specs, t_str *argument_str)
{
	if (argument_specs->show_sign)
		adjust_width_precision_for_sign(argument_specs);
	if (argument_specs->show_sign && argument_specs->zeros_width)
		apply_plus_minus_flags(argument_specs, argument_str);
	if (argument_specs->width && !(argument_specs->left_align_output))
		apply_width(argument_specs, argument_str);
	if (argument_specs->show_sign && !argument_specs->zeros_width)
		apply_plus_minus_flags(argument_specs, argument_str);
	if (argument_specs->sharp)
		apply_sharp(argument_specs, argument_str);
	if (argument_specs->precision > 1)
		apply_precision(argument_specs, argument_str);
	/*
	else if (argument_specs->precision == 1
			&& argument_specs->width > argument_specs->arg_len)
		argument_str->position -= argument_specs->arg_len;
		*/
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
	argument.zeros_width = 0;
	argument.precision = 1;
	argument.show_sign = 0;
	argument.percentage_presence = 0;
	argument.left_align_output = 0;

	return (argument);
}

static void		find_arg_len(va_list ap, t_printf *argument_specs)
{
	va_list copy;

	va_copy(copy, ap);
	if (ft_strchr("ouxXdiOUDb", argument_specs->type))
		argument_specs->arg_len = get_number_len(copy, argument_specs);
	else if (ft_strchr("cCsS", argument_specs->type))
		argument_specs->arg_len = get_char_len(copy, argument_specs);
}

static int		parsing_handler(const char *format, va_list ap)
{
	t_printf	argument_specs;
	t_str		argument_str;

	argument_str.position = 0;
	while (format && *format)
	{
		argument_specs = initialize_elem();
		format = parse(format, &argument_specs, &argument_str, ap);
		if (argument_specs.type)
			find_arg_len(ap, &argument_specs);
		if (argument_specs.width
			|| argument_specs.precision > 1 || argument_specs.sharp ||
			argument_specs.show_sign)
			apply_precision_width(&argument_specs, &argument_str);
		if (argument_specs.type && argument_specs.precision >= 1)
			treat_and_store_argument(ap, &argument_specs, &argument_str);
		if (argument_specs.width && argument_specs.left_align_output)
			apply_width(&argument_specs, &argument_str);
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
	return (return_val);
}
