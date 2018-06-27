/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_str_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 22:52:09 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/27 10:06:56 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

void	stack_str_fill(t_printf	*argument, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		(*argument).arg[set_get_arg_len(1)] = src[i];
		i++;
	}
}

void	erase_arg_str(t_printf	*argument)
{
	ft_memset((*argument).arg, 0, set_get_arg_len(0));
	set_get_arg_len(4097);
}
