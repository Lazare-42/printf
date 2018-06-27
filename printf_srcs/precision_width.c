/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:13:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/27 19:03:56 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

void		apply_width(t_printf *argument)
{
	int		arg_len;
	int		i;

	i = -1;
	arg_len = set_get_arg_len(0);
	if (arg_len < (*argument).width)
	{
		ft_memset(argument->tmp, ' ', (*argument).width - arg_len);
		ft_memcpy(argument->tmp + (*argument).width - arg_len, (*argument).arg, arg_len);
		argument->tmp[(*argument).width] = 0;
		stack_str_fill(argument, argument->tmp, (*argument).width);
	}
}

void		apply_flag_padding(t_printf *argument)
{
	int		arg_len;

	arg_len = set_get_arg_len(0);
	if (arg_len >= argument->width && argument->precision == -1 )
		return ;
	if ((*argument).left_align_output == 1)
	{
		ft_memcpy(argument->tmp, (*argument).arg, arg_len);
		ft_memset(argument->tmp + arg_len, ' ', (*argument).width - arg_len);
	}
	else if (!((*argument).left_align_output))
	{
		ft_memset(argument->tmp, '0', (*argument).width - arg_len);
		if (ft_strchr("dDioOuUxX", argument->type) && argument->arg[0] == '-')
		{
			argument->tmp[0] = '-';
			argument->arg[0] = '0';
		}
		ft_memcpy(argument->tmp + (*argument).width - arg_len, (*argument).arg, arg_len);
	}
	argument->tmp[(*argument).width] = 0;
	stack_str_fill(argument, argument->tmp, argument->width);
}

void		apply_plus_minus_flags(t_printf *argument)
{
	int i;
	int	arg_len;

	i = -1;
	arg_len = set_get_arg_len(0);
	if (*((*argument).arg) != '-')
	{
		while (++i < arg_len)
			argument->arg[arg_len - i] = argument->arg[arg_len - i - 1];
		if ((*argument).show_sign == '+')
			(*argument).arg[0] = '+';
		else if ((*argument).show_sign == ' ')
			(*argument).arg[0] = ' ';
		if (argument->precision > 0)
			(*argument).arg[0] = '0';
		set_get_arg_len(1);
	}
}

void		apply_precision(t_printf *argument)
{
	int		arg_len;
	int		i;

	i = -1;
	arg_len = set_get_arg_len(0);
	if (!(*argument).precision && (*argument).type == 's')
		return ;
	if (ft_strchr("diouxX", (*argument).type) && (*argument).precision > arg_len)
	{
		ft_memset(argument->tmp, '0', argument->precision - arg_len);
		ft_memcpy(argument->tmp + (*argument).precision - arg_len, argument->arg, argument->precision);
		stack_str_fill(argument, argument->tmp, argument->precision);
	}
	if (!(*argument).precision && ft_strchr("diouxX", (*argument).type) && *(*argument).arg == '0')
		erase_arg_str(argument);
	else if ((*argument).type == 's')
	{
		while (set_get_arg_len(0) > (*argument).precision)
			(*argument).arg[set_get_arg_len(-1)] = 0;
	}
}

void		apply_sharp(t_printf *argument)
{
	int		arg_len;
	int		i;

	i = -1;
	arg_len = set_get_arg_len(0);
	if ((*argument).type == 'o')
	{
		while (++i < arg_len)
			argument->arg[arg_len] = argument->arg[arg_len - i]; 
		argument->arg[0] = '0';
		set_get_arg_len(1);
	}
	else if ((*argument).arg[0] != '0')
	{
		while (++i < arg_len)
			 (*argument).arg[i + 2] = (*argument).arg[i];
		(*argument).arg[0] = '0'; 
		(*argument).arg[1] = ((*argument).type == 'x') ? 'x' : 'X';
		set_get_arg_len(2);
	}
}
