/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_base_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:00:36 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/26 18:13:07 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"
#include <inttypes.h>

/*
** u in ft_u_base_converter stands for unsigned base converter
** take_out_bits' utility is to take out bits if a signed value has been passed
** to the function ; and this value type is smaller than a uintmax_t ; the
** largest possible type in C
*/

unsigned long long	take_out_bits(uintmax_t to_change, int sizeof_var)
{
	static unsigned long long	all_bits_long_long = ~0;
	static unsigned long		all_bits_long = ~0;
	static unsigned int			all_bits_int = ~0;
	static unsigned short		all_bits_short = ~0;
	static unsigned char		all_bits_char = ~0;

	if (sizeof(unsigned long long) == sizeof_var)
		to_change &= all_bits_long_long;
	else if (sizeof(unsigned long) == sizeof_var)
		to_change &= all_bits_long;
	else if (sizeof(unsigned int) == sizeof_var)
		to_change &= all_bits_int;
	else if (sizeof(unsigned short) == sizeof_var)
		to_change &= all_bits_short;
	else if (sizeof(unsigned char) == sizeof_var)
		to_change &= all_bits_char;
	return (to_change);
}

void				printf_u_base_converter(int base_size, uintmax_t number,
		int sizeof_var, t_printf *argument)
{
	static char	base_output[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char		result[sizeof_var * 8];
	int			i;

	i = 0;
	number = take_out_bits(number, sizeof_var);
	(number == 0) ? result[sizeof_var * 8] = '0' : 0;
	while (number)
	{
		result[sizeof_var * 8 - i] = base_output[number % base_size];
		number /= base_size;
		i++;
	}
	while (i >= 0)
	{
		(*argument).arg[set_get_arg_len(1)] = result[sizeof_var * 8 - i];
		i--;
	}
}
