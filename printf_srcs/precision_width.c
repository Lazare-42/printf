/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:13:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/19 22:22:15 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

void		apply_width(t_printf *argument_specs, t_str *argument_str)
{
	char	fill;
	int		fill_val;

	if (argument_specs->precision == -1)
		argument_specs->precision++;
	if (argument_specs->precision > argument_specs->width && argument_specs->type != 's')
		return ;
	fill = (argument_specs->left_align_output
			== 0 && !argument_specs->precision) ? '0' : ' ';
	fill_val = argument_specs->width;
	if (ft_strchr("sS", argument_specs->type) && argument_specs->precision)
		fill_val -= (argument_specs->precision < argument_specs->arg_len) ?
			argument_specs->precision : argument_specs->arg_len;
	else
		fill_val -= (argument_specs->precision < argument_specs->arg_len) ?
			argument_specs->arg_len : argument_specs->precision;
	if (fill_val <= 0)
		return ;
	if (argument_specs->show_sign)
		fill_val--;
	update_str(argument_str, (void*)&fill, 1);
}

void		apply_flag_padding(t_printf *argument_specs, t_str *argument_str)
{
	char	fill;

	fill = (argument_specs->precision < argument_specs->width &&
			argument_specs->precision != -1) ? ' ' : '0';
	if (argument_specs->arg_len >= argument_specs->width)
		return ;
	if (!((*argument_specs).left_align_output))
	{
		if (ft_strchr("dDioOuUxX", argument_specs->type) &&
				argument_specs->sign[0] && fill == '0')
		{
			update_str(argument_str, (void*)&argument_specs->sign[0], 1);
			update_str(argument_str, (void*)&fill, 1);
			return ;
		}
		update_str(argument_str, (void*)&fill, 1);
		update_str(argument_str, (void*)&argument_specs->sign[0], 1);
	}
}

void		apply_plus_minus_flags(t_printf *argument_specs, t_str *argument_str)
{
	if (ft_strchr("uS", argument_specs->type))
		return ;
	if (ft_strchr("cCsOo", argument_specs->type))
		return ;
	update_str(argument_str, (void*)&argument_specs->show_sign, 1);
}

void		apply_precision(t_printf *argument_specs, t_str *argument_str)
{
	char		fill;

	fill = '0';
	if (argument_specs->precision <= argument_specs->arg_len
			|| ft_strchr("sSCc", argument_specs->type))
		return ;
	update_str(argument_str, (void*)&fill, 1);
}

void		apply_sharp(t_printf *argument_specs, t_str *argument_str)
{
	char fill;

	fill = '0';
	update_str(argument_str, (void*)&fill, 1);
	if (ft_strchr("xXp", argument_specs->type))
	{
		fill = (argument_specs->type == 'X') ? 'X' : 'x';
		update_str(argument_str, (void*)&fill, 1);
	}
}
