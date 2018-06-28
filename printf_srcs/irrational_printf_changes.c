/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irrational_printf_changes.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 08:53:40 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/28 09:08:26 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

void	irrational_printf_changes(t_printf	*argument)
{
	if (set_get_arg_len(0) == 1 && (argument->type == 'x' || argument->type == 'X'))
	{
		(void)(argument);
	}
}
