/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_base_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:00:36 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/16 15:58:27 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"
#include <inttypes.h>
#include <stdio.h>

int							u_base_converter_len(int base_size,
		uintmax_t number, int sizeof_var)
{
	int			i;

	i = 0;
	number = take_out_bits(number, sizeof_var);
	(number == 0) ? i++ : 0;
	while (number)
	{
		number /= base_size;
		i++;
	}
	return (i);
}

int							s_base_converter_len(int base_size,
		intmax_t number, int sizeof_var)
{
	int				i;

	i = 0;
	number = convert_overflow(sizeof_var, number);
	if (number < 0)
	{
		i++;
		number *= -1;
	}
	(number == 0) ? i++ : 0;
	while (number != 0)
	{
		number /= base_size;
		i++;
	}
	return (i);
}
