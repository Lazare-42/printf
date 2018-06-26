/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:12:53 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/26 09:19:21 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "printf.h"
#include "../includes/libft.h"

static t_printf	*initialize_elem(t_printf *new_list_element)
{
	new_list_element->before = NULL;
	new_list_element->arg = NULL;
	new_list_element->type = '0';
	ft_memset(new_list_element->modifier, 0, 3);
	new_list_element->width = 0;
	new_list_element->sharp = 0;
	new_list_element->precision = -1;
	new_list_element->show_sign = 0;
	new_list_element->left_align_output = -1;
	new_list_element->next = NULL;
	return (new_list_element);
}

static t_printf	*new_list_element(void)
{
	t_printf *new_list_element;

	new_list_element = NULL;
	if (!(new_list_element = malloc(sizeof(t_printf))))
		return (ft_put_error_return_null("malloc error", "new_list_element"));
	new_list_element = initialize_elem(new_list_element);
	return (new_list_element);
}

void			free_lst(t_printf **elem)
{
	t_printf *tmp;

	tmp = NULL;
	while (*elem)
	{
		tmp = *elem;
		*elem = (*elem)->next;
		ft_memdel((void*)&tmp);
	}
}

t_printf		*set_get_arg_list(int get_first)
{
	static t_printf	*arg_list = NULL;
	t_printf		*tmp;
	t_printf		*new;

	tmp = NULL;
	new = NULL;
	if (get_first < 0)
		free_lst(&arg_list);
	if (!(arg_list))
	{
		if (!(arg_list = new_list_element()))
			return (NULL);
		else
			return (arg_list);
	}
	if (get_first)
		return (arg_list);
	tmp = arg_list;
	while (tmp->next)
		tmp = tmp->next;
	if (!(new = new_list_element()))
		return (NULL);
	else
		tmp->next = new;
	return (new);
}
