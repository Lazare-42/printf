/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:01:32 by lazrossi          #+#    #+#             */
/*   Updated: 2018/09/05 10:26:59 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

typedef struct		s_printf
{
	char			*arg;
	char			*before;
	char			*after;
	int				width;
	int				precision;
	struct s_printf	*next;
}					t_printf;

char	*width_padding(char *printf_str, int int_nbr);
int		printf(const char *restrict format, ...);
char	char_type_add(char c);
int		set_get_precision(int yes);

#endif
