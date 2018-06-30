/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_store_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:44:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/30 23:34:44 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include <wchar.h>
#include <unistd.h>
#include "../includes/libft.h"

void	store_values(t_printf	*arg, void	*dst, int src_len, int sizeof_memop)
{
	unsigned char	*src_byte;
	unsigned char	*dst_byte;
	int				i;
	int				stack_len;

	i = 0;
	dst_byte = dst;
	src_byte = arg->to_store;
	stack_len = (arg->location == 1) ? arg->before_arg_len : arg->before_len;
	stack_len = (arg->location == 2) ? arg->before_len : arg->arg_len;
	while (sizeof_memop--)
	{
		if (stack_len == BUFF_SIZE / 3)
			store_print_handler(arg, -arg->location, 0, 0);
		dst_byte[stack_len] = src_byte[i];
		stack_len++;
		if (src_len)
			i++;
	}
	ft_putnbr(stack_len);
	ft_putchar('\n');
	if (arg->location == 1)
		arg->before_arg_len += stack_len;
	else if (arg->location == 2)
		arg->before_arg_len += stack_len;
	else
		arg->arg_len += stack_len;
}

void		print(t_printf *arg, void *str, int location)
{
	unsigned char	final_str[BUFF_SIZE];
	int				write_size;

	write_size = 0;
	ft_memcpy(final_str, str, arg->before_len);
	write_size += arg->before_len;
	arg->before_len = 0;
	if (location == -2 || location == -3)
	{
		ft_memcpy(final_str + write_size, str + BUFF_SIZE / 3, arg->before_arg_len);
		write_size += arg->before_arg_len; 
		arg->before_arg_len = 0;
	}
	if (location == -3)
	{
		ft_memcpy(final_str + write_size, str + 2 * (BUFF_SIZE / 3), arg->arg_len);
		write_size += arg->arg_len; 
		arg->arg_len = 0;
	}
	debug();
	ft_putnbr(write_size);
	set_get_return(write(1, final_str, write_size));
}

void		store_print_handler(t_printf	*arg, int location, int src_len, int
		sizeof_memop)
{
	static unsigned char	str[BUFF_SIZE];

	if (location == 1)
		store_values(arg, (void*)str, src_len, sizeof_memop);
	else if (location == 2)
		store_values(arg, (void*)str + BUFF_SIZE / 3, src_len, sizeof_memop);
	else if (location == 3)
	{
		store_values(arg, (void*)str + 2 * BUFF_SIZE / 3, src_len, sizeof_memop);
	}
	if (location == 1 || location == 2 || location == 3)
		return ;
	else
		print(arg, str, location);
}

t_printf	initialize_elem(void)
{
	t_printf argument;

	argument.type = '0';
	ft_memset(argument.modifier, 0, 3);
	ft_memset(argument.sign, 0, 3);
	argument.before_len = 0;
	argument.before_arg_len = 0;
	argument.arg_len = 0;
	argument.width = 0;
	argument.sharp = 0;
	argument.precision = 0;
	argument.show_sign = 0;
	argument.left_align_output = -1;
	return (argument);
}
