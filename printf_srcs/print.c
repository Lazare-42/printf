/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:29:31 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/27 11:39:35 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
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
