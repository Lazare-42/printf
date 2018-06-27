/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_adr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:11:11 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/27 09:35:59 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

/*
** this function produces the string for the %p type
** FYI uintptr_t is the only type guaranteed to hold a pointer value
** argument_precision is only present because printf("%p, (void*)0)
** procuces 0x0 whereas printf("%.p, (void*)0) produces 0x
*/

// DEBUGGING NOTE : wihout testing I changed the adress producing function from
// an s_base_converter to an u_base_converter

void	get_hex_ptr_adr(va_list ap, t_printf *argument)
{
	void	*test_data;
	char	*tmp;

	test_data = NULL;
	tmp = NULL;
	test_data = va_arg(ap, void*);
	stack_str_fill(argument, "0x");
	if (test_data == 0 && (*argument).precision)
		stack_str_fill(argument, "0");
	else 
		printf_u_base_converter(16, (uintptr_t)test_data,
				sizeof(uintptr_t), argument);
}
