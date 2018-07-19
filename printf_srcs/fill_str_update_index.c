/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str_update_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:31:16 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/19 21:56:01 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../includes/libft.h"

void	update_str(t_str	*argument, void *to_cpy, int mem_op_size)
{
	ft_memcpy(argument->str + argument->position, to_cpy, mem_op_size);
	argument->position += mem_op_size;
}
