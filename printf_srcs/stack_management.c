/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:12:53 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/30 15:40:44 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include <wchar.h>
#include "../includes/libft.h"

void		print_all(void	*str_1, void *str_2, void *str_3, t_printf *arg)
{
	unsigned char 	string[3000];

	if (str_1)
		ft_memcpy(string, str_1, arg->before_len);
	if (str_2)
		ft_memcpy(string + arg->before_len, str_1, arg->before_arg_len);
	if (str_3)
		ft_memcpy(string + arg->before_len + arg->before_arg_len, str_1,
				arg->arg_len);
	write(1, &string, arg->before_len + arg->before_arg_len + arg->arg_len);
	if (str_1)
		arg->before_len = 0;
	if (str_2)
		arg->before_arg_len = 0;
	if (str_3)
		arg->arg_len = 0;
}

void		print_store_front_string(t_printf *arg)
{
	static	unsigned	char	string[1000];
	unsigned	char			*dest_byte;

	if (sizeof_var < 0 && !arg->before_len)
		return ;
	if (sizeof_var < 0)
	{
		print_all(string, NULL, NULL, arg);
		return ;
	}
	dest_byte = arg->to_store;
	if ((arg->before_len) > 999)
	{
		set_get_return(write(1, &string, arg->before_len - 1));
		arg->before_len = 0;
	}
	string[arg->before_len] = dest_byte[0];
	arg->before_len++;
}

// for now we assume sizeof_var is always 1 ; aka we are always storing some chars	
void		print_store_before_arg(t_printf *arg, int memset_siz)
{
	static	unsigned	char	string[1000];
	unsigned	char			*dest_byte;

	if (memset_siz < 0)
	{
		print_all(NULL, string, NULL, arg);
		return ;
	}
	dest_byte = arg->to_store;
	while (memset_siz--)
	{
		if ((arg->before_arg_len) > 999)
		{
			set_get_return(write(1, &string, arg->before_arg_len - 1));
			arg->before_arg_len = 0;
			ft_memset(string, 0, 1000); 
		}
		string[arg->before_arg_len] = *dest_byte;
		arg->before_arg_len++;
	}
}

void		print_store_arg(t_printf *arg, int sizeof_var, int cpy_size)
{
	static	unsigned char	string[1000];
	unsigned	char			*dest_byte;
	int						i;

	i = 0;
	if (cpy_size < 0)
	{
		print_all(NULL, NULL, string, arg);
		return ;
	}
	dest_byte = arg->to_store;
	while (cpy_size--)
	{
		if ((arg->arg_len) > 999)
		{
			set_get_return(write(1, &string, arg->arg_len - 1));
			arg->arg_len = 0;
		}
		string[arg->arg_len] = dest_byte[i];
		arg->before_arg_len++;
		if (sizeof_var)
			i++;
	}
}

void		store_print_handler(t_printf	*arg, int location, int increment, int
		memset)
{
	if (location == 1)
		print_store_front_string(arg, sizeof_var);
	else if (location == 2)
		print_store_before_arg(arg, sizeof_var, memset);
	else if (location == 3)
		print_store_arg(arg, sizeof_var, memset);
	else
	{
		print_store_front_string(arg, -1);
		if (arg->left_align_output != 1 || arg->sharp)
		{
			print_store_before_arg(arg, sizeof_var, -1);
			print_store_arg(arg, sizeof_var, -1);
		}
		else
		{
			print_store_arg(arg, sizeof_var, -1);
			print_store_before_arg(arg, sizeof_var, -1);
		}
	}
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
