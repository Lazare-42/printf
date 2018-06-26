/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:01:32 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 10:02:56 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

#include <stdarg.h>

typedef struct		s_printf
{
	char			*before;
	char			*arg;
	char 			type;
	char			modifier[3];
	char			left_align_output;
	char			show_sign;
	char			sharp;
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
char 				*treat_and_store_argument(va_list ap, t_printf **argument,
		char *format);
char				*get_flags(t_printf **argument, char *format);
char				*get_precision(va_list ap, t_printf **argument, char *format);
char				*get_width(va_list ap, t_printf **argument, char *format);
char				set_get_flags_presence(int yes);
int					set_get_return(int value);
int					print_list(void);
char				*get_hex_ptr_adr(va_list ap, int argument_precision);
t_printf			*apply_precision_width(t_printf *argument);
t_printf			*apply_width(t_printf *argument);
t_printf			*apply_flag_padding(t_printf *argument);
t_printf			*apply_plus_minus_flags(t_printf *argument);
t_printf			*apply_precision(t_printf *argument);
t_printf			*apply_sharp(t_printf *argument);
char				*store_modifier(t_printf **argument, char *format);
t_printf			*store_type_data(va_list ap, t_printf *argument);

#endif
