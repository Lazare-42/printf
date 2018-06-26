/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_adr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:11:11 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 10:00:41 by lazrossi         ###   ########.fr       */
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

char	*get_hex_ptr_adr(va_list ap, int argument_precision)
{
	void	*test_data;
	char	*tmp;

	test_data = NULL;
	tmp = NULL;
	test_data = va_arg(ap, void*);
	if (test_data == 0 && argument_precision)
	{
		if (!(tmp = ft_strdup("0")))
			return (NULL);
	}
	else if (!(tmp = ft_s_base_converter(16, (uintptr_t)test_data)))
		return (NULL);
	if (!(tmp = ft_joinfree_heapstr_stackstr(&tmp, "0x", 'a')))
		return (NULL);
	return (tmp);
}
