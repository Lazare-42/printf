/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_base_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:00:36 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/28 16:36:13 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"
#include <inttypes.h>
#include <stdio.h>

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
	static char	base_X_output[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char		result[sizeof_var * 8 + 1];
	int			i;

	i = 0;
	number = take_out_bits(number, sizeof_var);
	(number == 0) ? result[sizeof_var * 8] = '0' : 0;
	(number == 0) ? i++ : 0;
	while (number)
	{
		if ((*argument).type != 'X')
			result[sizeof_var * 8 - i] = base_output[number % base_size];
		else
			result[sizeof_var * 8 - i] = base_X_output[number % base_size];
		number /= base_size;
		i++;
	}
	ft_memcpy((*argument).arg, result + sizeof_var * 8 - i + 1, i);
	set_get_arg_len(i);
}

int					check_negativity(intmax_t number, int sizeof_var)
{
	if ((1 << (sizeof_var * 8 - 1)) & number)
		return (1);
	else
		return (0);
}

intmax_t				convert_overflow(int sizeof_var, intmax_t number)
{
	if ((int)sizeof(number) > sizeof_var)
	{
		if (sizeof_var == sizeof(short))
			number = (short)number;
		if (sizeof_var == sizeof(int))
			number = (int)number;
		if (sizeof_var == sizeof(long))
			number = (long)number;
			number = (long)number;
	}
	return (number);
}

void				printf_s_base_converter(int base_size, intmax_t number,
		int sizeof_var, t_printf *argument)
{
	static char	base_output[36] = "0123456789abcdefghijklmnopqrstuvwxyz";
	static char	base_X_output[36] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char		result[sizeof_var * 8 + 1];
	int			i;
	int			sign;

	i = 0;
	sign = 0;
	number = convert_overflow(sizeof_var, number);
	if (number < 0)
		sign = 1;
	if (number < 0)
		number *= -1;
	(number == 0) ? result[sizeof_var * 8] = '0' : 0;
	(number == 0) ? i++ : 0;
	while (number)
	{
		if ((*argument).type != 'X')
			result[sizeof_var * 8 - i] = base_output[number % base_size];
		else
			result[sizeof_var * 8 - i] = base_X_output[number % base_size];
		number /= base_size;
		i++;
	}
	(sign) ? result[sizeof_var * 8 - i] = '-' : 0;
	(sign) ? i++ : 0;
	ft_memcpy((*argument).arg, result + sizeof_var * 8 - i + 1, i);
	set_get_arg_len(i);
}

