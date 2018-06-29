/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:12:53 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/29 09:38:30 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "../includes/libft.h"

void	print_flush(t_printf argument)
{
	int			return_val;

	return_val = 0;
	return_val = write(1, &(argument.before), set_get_before_len(0));
	return_val += write(1, &(argument.arg), set_get_arg_len(0));
	set_get_before_len(4097);
	set_get_arg_len(4097);
	set_get_return(return_val);
}

void		write_before(t_printf	*argument)
{
	static int before = 1999;
}

void		write_after(t_printf	*argument)
{
	static int after = 2000;
}

void		store_print_handler(char to_store, int location, int first_access)
{
	static	t_printf	argument;
	static int			first = 1;

	if (first_access)
	{
		argument = initialize_elem();
		first = 0;
	}
	if (location == 1)
		argument = print_store_front_string(to_store, argument);
	else if (location == 2)
		argument = print_store_before_arg(to_store, argument);
	else if (location == 3)
		argument = print_store_arg(to_store, argument);
	else
		argument = print_flush(argument);
}

t_printf	initialize_elem(void)
{
	t_printf new_list_element;

	new_list_element.type = '0';
	ft_memset(new_list_element.modifier, 0, 3);
	new_list_element.width = 0;
	new_list_element.sharp = 0;
	new_list_element.precision = -1;
	new_list_element.show_sign = 0;
	new_list_element.left_align_output = -1;
	return (new_list_element);
}
