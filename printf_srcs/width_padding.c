/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:37:48 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 10:00:39 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

/*
** the function width_padding applies the padding according the its sign
** for numeral objects.
** As you might not know, if the sign is < 0, width padding comes afterwards
** the object, otherwise it comes before
*/

char	*width_padding(char *printf_str, int int_nbr)
{
	static char	direction = '+';
	char		*padding_str;

	padding_str = NULL;
	if (int_nbr < 0)
	{
		direction = '-';
		int_nbr *= -1;
	}
	if (!(padding_str = ft_strnew(int_nbr)))
		return (ft_put_error_return_null("malloc error", "width_padding"));
	padding_str = ft_memset((void*)padding_str, ' ', int_nbr);
	if (direction == '-')
	{
		if (!(printf_str = ft_strjoinfree(&printf_str, &padding_str, 'B')))
			return (ft_put_error_return_null("malloc error", "width_padding"));
		return (printf_str);
	}
	if (!(printf_str = ft_strjoinfree(&padding_str, &printf_str, 'B')))
		return (ft_put_error_return_null("malloc error", "width_padding"));
	return (printf_str);
}
