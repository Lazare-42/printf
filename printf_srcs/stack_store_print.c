/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_store_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:44:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/30 15:40:46 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include <wchar.h>
#include "../includes/libft.h"

void		store_print_values(t_printf		*arg, void	*dst, int src_len, int sizeof_memop, int location)
{
	unsigned char	*dest_byte;
	int				i;
	int				stack_len;

	i = 0;
	dest_byte = dst;
	stack_len = (location = 1) ? arg->before_arg_len : arg->before_len;
	stack_len = (location = 2) ? arg->before_len : arg->arg_len;
	while (sizeof_memop--)
	{
		if (*location > 999)
		{
			store_print_handler(arg, 0, 
		}
	}
}

void		store_print_handler(t_printf	*arg, int location, int src_len, int
		sizeof_memop)
{
	static unsigned char	before_arg[1000];
	static unsigned char	padding_arg[1000];
	static unsigned char	arg;[1000]

	arg->location = location;
}
