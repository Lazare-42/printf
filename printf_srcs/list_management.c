/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:12:53 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/28 08:58:42 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "../includes/libft.h"

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
