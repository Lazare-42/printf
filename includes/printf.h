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

#include <stdarg.h>

typedef struct		s_printf
{
	char			*before;
	char			*arg;
	char 			sign;
	char			width_type;
	char			left_align_output;
	char			show_sign;
	int				width;
	int				precision;
	struct s_printf	*next;
}					t_printf;

char				*width_padding(char *printf_str, int int_nbr);
int					printf(const char *restrict format, ...);
char				char_type_add(char c);
int					set_get_precision(int yes);
int					ft_printf(const char *restrict format, ...);
t_printf			*set_get_arg_list(int get_first);
char 				*treat_and_store_argument(va_list ap, t_printf **argument, char *format);
char				*get_flags(t_printf **argument, char *format);

#endif
