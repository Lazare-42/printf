/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:13:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/29 09:38:32 by lazrossi         ###   ########.fr       */
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
	if (arg_len < argument->width)
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
	char	fill;

	fill = (argument->precision < argument->width &&
			argument->precision != -1) ? ' ' : '0';
	arg_len = set_get_arg_len(0);
	if (arg_len >= argument->width)
		return ;
	if ((*argument).left_align_output == 1)
	{
		ft_memcpy(argument->tmp, (*argument).arg, arg_len);
		ft_memset(argument->tmp + arg_len, ' ', (*argument).width - arg_len);
	}
	else if (!((*argument).left_align_output))
	{
		ft_memset(argument->tmp, fill, (*argument).width - arg_len);
		if (ft_strchr("dDioOuUxX", argument->type) && (argument->arg[0] == '-'
					|| argument->arg[0] == '+'))
		{
			argument->tmp[0] = (argument->arg[0] == '-') ?  '-' : '+';
			argument->arg[0] = '0';
		}
		ft_memcpy(argument->tmp + argument->width - arg_len, argument->arg, arg_len);
	}
	argument->tmp[(*argument).width] = 0;
	stack_str_fill(argument, argument->tmp, argument->width);
}

void		apply_plus_minus_flags(t_printf *argument)
{
	int i;
	int	arg_len;

	i = -1;
	if (argument->type == 'u')
		return ;
	arg_len = set_get_arg_len(0);
	if (*argument->arg != '-' || set_get_put_sign_back(0))
	{
		while (++i < arg_len)
			argument->arg[arg_len - i] = argument->arg[arg_len - i - 1];
		if (set_get_put_sign_back(0) < 0)
			argument->arg[0] = '-';
		if ((*argument).show_sign == ' ' && argument->type != 'u')
			argument->arg[0] = ' ';
		else if ((*argument).show_sign == '+' || set_get_put_sign_back(0) > 0)
			argument->arg[0] = '+';
		set_get_arg_len(1);
	}
}

void		apply_precision(t_printf *argument)
{
	int		arg_len;

	arg_len = set_get_arg_len(0);
	if (argument->precision < arg_len)
		return ;
	if (argument->arg[0] && ft_strchr("diouxX", argument->type))
		argument->arg[set_get_arg_len(-1)] = '0';
	if ((*argument->arg == '-') && arg_len - 1 < argument->precision && ft_strchr("diouxX", argument->type))
	{
		(*argument->arg == '-') ? set_get_put_sign_back(-1) : set_get_put_sign_back(1);
		set_get_arg_len(1);
		argument->arg[0] = '0';
	}
	if (ft_strchr("diouxX", argument->type))
	{
		ft_memset(argument->tmp, '0', argument->precision - arg_len);
		ft_memcpy(argument->tmp + argument->precision - arg_len, argument->arg, argument->precision);
		stack_str_fill(argument, argument->tmp, argument->precision);
	}
	if (!argument->precision && ft_strchr("diuxX", argument->type) && *argument->arg == '0')
		erase_arg_str(argument);
	else if ((*argument).type == 's' && argument->precision)
	{
		while (set_get_arg_len(0) > (*argument).precision)
			(*argument).arg[set_get_arg_len(-1)] = 0;
	}
}


// this function is broken in certain cases
void		apply_sharp(t_printf *argument)
{
	int		arg_len;
	int		i;

	i = -1;
	arg_len = set_get_arg_len(0);
	if (argument->width < argument->precision || argument->precision == -1)
		(argument->type == 'o') ? set_get_arg_len(1) : set_get_arg_len(2);
	if (argument->type == 'o')
	{
	if (argument->width < argument->precision || argument->precision == -1)
			while (++i < arg_len && ft_isdigit(argument->arg[arg_len - i - 1]))
				argument->arg[arg_len - i] = argument->arg[arg_len - i - 1];
		argument->arg[i] = '0';
		return ;
	}
	if (argument->width < argument->precision || argument->precision == -1)
		while (++i < arg_len)
			argument->arg[arg_len - i + 1] = argument->arg[arg_len - i - 1];
	argument->arg[0] = '0'; 
	argument->arg[1] = (argument->type == 'x') ? 'x' : 'X';
}
