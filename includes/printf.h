/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:01:32 by lazrossi          #+#    #+#             */
/*   Updated: 2018/07/07 15:22:22 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# define BUFF_SIZE 12288

# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>

typedef struct		s_printf
{
	int				before_len;
	int				before_arg_len;
	int				arg_len;
	int				location;
	void			*to_store;
	char			percentage_presence;
	char			type;
	char			modifier[3];
	char			sign[3];
	char			left_align_output;
	char			show_sign;
	char			sharp;
	int				width;
	int				precision;
}					t_printf;

int					ft_printf(const char *restrict format, ...);
void				store_char_data(va_list ap, t_printf *argument);
void				store_number_data(va_list ap, t_printf *argument);
char				*parse(char *format, t_printf *argument, va_list ap);
void				get_flags(t_printf *argument, char *format);
void				get_precision(va_list ap, t_printf *argument, char *format);
void				get_width(va_list ap, t_printf *argument, char *format);
void				get_modifier(t_printf *argument, char *format);
void				get_hex_ptr_adr(va_list ap, t_printf *argument);
void				apply_width(t_printf *argument);
void				apply_flag_padding(t_printf *argument);
void				apply_plus_minus_flags(t_printf *argument);
void				apply_precision(t_printf *argument);
void				apply_sharp(t_printf *argument);
void				printf_u_base_converter(int base_size, uintmax_t number,
		int sizeof_var, t_printf *argument);
void				printf_s_base_converter(int base_size, intmax_t number,
		int sizeof_var, t_printf *argument);
void				store_print_handler(t_printf *argument, int location,
		int sizeof_var, int memset);
int					set_get_return(int action);
void				store_unicode(wint_t data, t_printf *argument,
		int precision);
void				store_unicode_str(wchar_t *data, t_printf *argument);

#endif
