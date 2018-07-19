/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_and_store_argument.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:30:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/19 21:50:51 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"
#include <stdarg.h>

void		store_str_data(va_list ap, t_str *argument_str)
{
	char	*va_arg_str;
	int		strlen;

	va_arg_str = NULL;
	strlen = 0;
	va_arg_str = va_arg(ap, char *);
	if (!va_arg_str)
		update_str(argument_str, (void*)"(null)", 6);
	else
	{
		strlen = ft_strlen(va_arg_str);
		update_str(argument_str, (void*)va_arg_str, strlen);
	}
}

void		store_char_data(va_list ap, t_printf *argument, t_str *argument_str)
{
	char c;

	if (argument->type == 's' && !*argument->modifier)
		store_str_data(ap, argument_str);
	else if ((*argument).type == 'c' && !*argument->modifier)
	{
		c = va_arg(ap, int);
		update_str(argument_str, (void*)&c, 1);
	}
	else if (argument->type == 'C'
			|| (argument->type == 'c' && *argument->modifier == 'l'))
		store_unicode(va_arg(ap, wint_t), argument, 4);
	else if (argument->type == 'S'
			|| (argument->type == 's' && *argument->modifier == 'l'))
		store_unicode_str(va_arg(ap, wchar_t*), argument);
//	if ((*argument).type == 'p')
//j		get_hex_ptr_adr(ap, argument);
}
