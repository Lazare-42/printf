/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:13:25 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/26 23:30:22 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

t_printf	*apply_width(t_printf *argument)
{
	char	*tmp;
	int		strlen;

	tmp = NULL;
	strlen = 0;
	if (argument->arg)
		strlen = ft_strlen((argument)->arg);
	if (strlen < (argument)->width)
	{
		tmp = ft_strnew((argument)->width);
		ft_memset(tmp, ' ', (argument)->width - strlen);
		(argument->arg) ? tmp = ft_strcat(tmp, (argument)->arg) : 0;
		(argument)->arg = tmp;
	}
	return (argument);
}

t_printf	*apply_flag_padding(t_printf *argument)
{
	char	*tmp;
	int		strlen;

	tmp = NULL;
	strlen = ft_strlen((argument)->arg);
	if (strlen >= argument->width)
		return (argument);
	if ((argument)->left_align_output == 1)
	{
		tmp = ft_strnew((argument)->width);
		ft_memcpy(tmp, (argument)->arg, strlen);
		ft_memset(tmp + strlen, ' ', (argument)->width - strlen);
	}
	else if (!((argument)->left_align_output))
	{
		tmp = ft_strnew((argument)->width);
		ft_memset(tmp, '0', (argument)->width - strlen);
		tmp = ft_strcat(tmp, (argument)->arg);
	}
	ft_memdel((void**)&((argument)->arg));
	(argument)->arg = tmp;
	return (argument);
}

t_printf	*apply_plus_minus_flags(t_printf *argument)
{
	if ((argument)->show_sign == ' ' && *((argument)->arg) != '-')
		(argument)->arg = ft_strjoinfree_char_str(' ', &(argument)->arg);
	else if ((argument)->show_sign == '+' && *((argument)->arg) != '-')
		(argument)->arg = ft_strjoinfree_char_str('+', &(argument)->arg);
	if (!(argument->arg))
		set_get_return(-1);
	return (argument);
}

t_printf	*apply_precision(t_printf *argument, char *va_arg_str)
{
	int		strlen;
	char	tmp[(*argument).precision];
	int		i;

	i = 0;
	if (!(*argument).precision && (*argument).type == 's')
		return ;
	strlen = ft_strlen(va_arg_str);
	if (ft_strchr("diouxX", (*argument).type) && (*argument).precision > strlen)
	{
		ft_memset(tmp, '0', (*argument).precision - strlen);
		while (va_arg_str[i])
			tmp[(*argument).precision - strlen + i + 1] = va_arg_str[i];
		stack_str_fill(argument, tmp);
	}
	// 
	// work
	// left here
	(!(*argument).precision && ft_strchr("diouxX", (*argument).type)
	 && *(*argument).arg == '0') ? ft_memdel((void*)&((*argument).arg)) : 0;
	else if ((*argument).type == 's')
		(*argument).arg = ft_strndup_free(&((*argument).arg), (*argument).precision);
	return (argument);
}

t_printf	*apply_sharp(t_printf *argument)
{
	if (argument->type == 'o')
		(*argument).arg[set_get_arg_len(1)] = '0'; 
	else if (argument->type == 'x' && *argument->arg != '0')
	{
		(*argument).arg[set_get_arg_len(1)] = '0'; 
		(*argument).arg[set_get_arg_len(1)] = 'x'; 
	}
	else if (argument->type == 'X' && *argument->arg != '0')
	{
		(*argument).arg[set_get_arg_len(1)] = '0'; 
		(*argument).arg[set_get_arg_len(1)] = 'X'; 
	}
	return (argument);
}
