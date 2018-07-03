/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:13:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/03 15:56:54 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

#include <stdio.h>

void		apply_width(t_printf *argument)
{
	char	fill;
	int		fill_val;

	if (argument->precision > argument->width)
		return ;
	fill = (argument->left_align_output 
			== 0) ? '0' : ' ';
	fill_val = argument->width;
	fill_val -= (argument->precision < argument->arg_len) ?
		argument->arg_len : argument->precision;
	if (argument->show_sign)
		fill_val--;
	argument->to_store = (void*)&fill;
	if (argument->left_align_output == 1)
		store_print_handler(argument, 3, 0, fill_val);
	else
		store_print_handler(argument, 2, 0, fill_val);
}

void		apply_flag_padding(t_printf *argument)
{
	char	fill;
	char	space_for_sign;

	space_for_sign = 0;
	fill = (argument->precision < argument->width &&
			argument->precision != -1) ? ' ' : '0';
	if (argument->arg_len >= argument->width)
		return ;
	if (!((*argument).left_align_output))
	{
		if (ft_strchr("dDioOuUxX", argument->type) &&
				argument->sign[0] && fill == '0')
		{
			argument->to_store = (void*)&(argument->sign[0]);
			store_print_handler(argument, 2, 1, 1);
			argument->to_store = (void*)&fill;
			store_print_handler(argument, 2, 1,
					argument->width - argument->arg_len);
			return ;
		}
		argument->to_store = (void*)&fill;
		store_print_handler(argument, 2, 1, argument->width - argument->arg_len);
		argument->to_store = (void*)&(argument->sign[0]);
		store_print_handler(argument, 2, 1, 1);
	}
}

// ok you need to store the flag directly in the function get_modifiers

void		apply_plus_minus_flags(t_printf *argument)
{
	if (argument->type == 'u')
		return ;
	argument->to_store = (void*)&(argument->show_sign);
	store_print_handler(argument, 2, 0, 1);
}

void		apply_precision(t_printf *argument)
{
	char		fill;

	fill = '0';
	if (argument->precision < argument->arg_len && argument->left_align_output)
		return ;
	argument->to_store = (void*)&fill;
	store_print_handler(argument, 2, 0, argument->precision - argument->arg_len);
}

void		apply_sharp(t_printf *argument)
{
	char fill;

	fill = '0';
	argument->to_store = (void*)&fill;
	store_print_handler(argument, 2, 1, 1);
	if (argument->type != 'o')
	{
		fill = (argument->type == 'X') ? 'X' : 'x';
		argument->to_store = (void*)&(argument->type);
		store_print_handler(argument, 2, 1, 1);
	}
}
