/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:52:50 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/19 22:52:36 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

void		store_unicode(wint_t data, int precision, t_str *argument_str)
{
	unsigned char	c[3];

	c[0] = data;
	if (data < 128 && precision)
		update_str(argument_str, (void*)&c, 1);
	else if (data < 2048 && precision > 1)
	{
		c[0] = (0b00011111 & (data >> 6)) | 0b11000000;
		c[1] = (0b00111111 & data) | 0b10000000;
		update_str(argument_str, (void*)&c, 2);
	}
	else if ((data < 131071 || data < 41943004) && precision > 2)
	{
		if (data > 131071)
		{
			if (precision == 3)
				return ;
			c[0] = (0b00001111 & (data >> 18)) | 0b11100000;
			update_str(argument_str, (void*)&c, 1);
		}
		c[0] = (0b00001111 & (data >> 12)) | 0b11100000;
		c[1] = (0b00111111 & (data >> 6)) | 0b10000000;
		c[2] = (0b00111111 & data) | 0b10000000;
		update_str(argument_str, (void*)&c, 3);
	}
}

void		store_unicode_str(wchar_t *data,  t_str *argument_str)
{
	if (!data)
		update_str(argument_str, (void*)"(null)", 6);
	else
		while (*data)
		{
			store_unicode(*data, 4, argument_str);
			data++;
		}
}
