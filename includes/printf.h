/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:01:32 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/27 16:40:55 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

#include <stdarg.h>
#include <inttypes.h>

typedef struct		s_printf
{
	char			before[4096];
	char			arg[4096];
	char			tmp[4096];
	char			character;
	char 			type;
	char			modifier[3];
	char			left_align_output;
	char			show_sign;
	char			sharp;
	int				width;
	int				precision;
}					t_printf;

char				*width_padding(char *printf_str, int int_nbr);
int					printf(const char *restrict format, ...);
char				char_type_add(char c);
int					set_get_precision(int yes);
int					ft_printf(const char *restrict format, ...);
t_printf			set_get_arg_list(void);
char 				*treat_and_store_argument(va_list ap, t_printf *argument,
		char *format);
char				*get_flags(t_printf *argument, char *format);
char				*get_precision(va_list ap, t_printf *argument, char *format);
char				*get_width(va_list ap, t_printf *argument, char *format);
char				*get_modifier(t_printf *argument, char *format);
char				set_get_flags_presence(int yes);
int					set_get_return(int value);
int					set_get_arg_len(int increment);
int					set_get_before_len(int increment);
void				print_flush(t_printf argument);
void				get_hex_ptr_adr(va_list ap, t_printf *argument);
void				apply_width(t_printf *argument);
void				apply_flag_padding(t_printf *argument);
void				apply_plus_minus_flags(t_printf *argument);
void				apply_precision(t_printf *argument);
void				apply_sharp(t_printf *argument);
void				store_type_data(va_list ap, t_printf *argument);
void				printf_u_base_converter(int base_size, uintmax_t number,
		int sizeof_var, t_printf *argument);
void				printf_s_base_converter(int base_size, intmax_t number,
		int sizeof_var, t_printf *argument);
void				stack_str_fill(t_printf	*argument, char *src, int size);
void				erase_arg_str(t_printf	*argument);

#endif
