/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:29:31 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/26 18:33:35 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

void	print_flush(t_printf argument)
{
	int			return_val;

	return_val = 0;
	return_val = write(1, &(argument.before), ft_strlen(argument.before));
	return_val += write(1, &(argument.arg), ft_strlen(argument.arg));
	set_get_return(return_val);
}
