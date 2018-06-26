/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_str_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 22:52:09 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/26 22:55:27 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

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
