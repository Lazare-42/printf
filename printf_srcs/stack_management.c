/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_store_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:44:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 15:35:48 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "../includes/libft.h"

static unsigned char	g_str[BUFF_SIZE];
static  unsigned char	g_final_str[BUFF_SIZE * 3];
static int				g_return_val = 0;

int						set_get_return(int action)
{
	int			final_ret;

	if (action < 0)
		g_return_val = action;
	if (g_return_val < 0)
		return (g_return_val);
	else if (action > 0)
		g_return_val += action;
	if (!action)
	{
		final_ret = g_return_val;
		g_return_val = 0;
		return (final_ret);
	}
	return (g_return_val);
}

static int				increment_right_value(t_printf *arg, int increment_val)
{
	if (arg->location == 1)
		return (arg->before_len += increment_val);
	else if (arg->location == 2)
		return (arg->before_arg_len += increment_val);
	else
		return (arg->arg_len += increment_val);
}

void					store_values(t_printf *arg, int buff_location,
		int src_len, int sizeof_memop)
{
	unsigned char	*src_byte;
	unsigned char	*dst_byte;
	int				i;

	i = 0;
	dst_byte = g_str + buff_location;
	src_byte = arg->to_store;
	while (sizeof_memop--)
	{
		if (increment_right_value(arg, 0) == BUFF_SIZE / 3)
			store_print_handler(arg, -arg->location, 0, 0);
		dst_byte[increment_right_value(arg, 1) - 1] = src_byte[i];
		if (src_len)
			i++;
	}
}

static void				print(t_printf *arg, int location)
{
	int				write_size;
	unsigned char	final_str[4096];

	write_size = 0;
	ft_memcpy(final_str, g_str, arg->before_len);
	write_size += arg->before_len;
	arg->before_len = 0;
	if (location == -2 || location == -3 || location == -4)
	{
		ft_memcpy(final_str + write_size, g_str
				+ BUFF_SIZE / 3, arg->before_arg_len);
		write_size += arg->before_arg_len;
		arg->before_arg_len = 0;
	}
	if (location == -3 || location == -4)
	{
		ft_memcpy(final_str + write_size, g_str + 2
				* (BUFF_SIZE / 3), arg->arg_len);
		write_size += arg->arg_len;
		arg->arg_len = 0;
	}
	if (write_size + g_return_val > BUFF_SIZE * 3)
	{
		set_get_return(write(1, &g_final_str, set_get_return(0)));
		ft_memcpy(g_final_str, final_str, write_size);
	}
	else if (write_size)
	{
		ft_memcpy(g_final_str + g_return_val, final_str, write_size);
		set_get_return(write_size);
	}
}

void					store_print_handler(t_printf *arg,
		int location, int src_len, int sizeof_memop)
{
	if (location > 0)
		arg->location = location;
	if (location == 1)
		store_values(arg, 0, src_len, sizeof_memop);
	else if (location == 2)
		store_values(arg, BUFF_SIZE / 3, src_len, sizeof_memop);
	else if (location == 3)
		store_values(arg, 2 * BUFF_SIZE / 3,
				src_len, sizeof_memop);
	if (location == 1 || location == 2 || location == 3)
		return ;
	else if (location == -4)
		print(arg, location);
	else if (g_return_val <= BUFF_SIZE * 3)
		set_get_return(write(1, &g_final_str, set_get_return(0)));
	else
		set_get_return(write(1, &g_final_str, g_return_val % (BUFF_SIZE * 3)));
}
