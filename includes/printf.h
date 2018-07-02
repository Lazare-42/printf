/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 16:54:45 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/30 23:26:28 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:01:32 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/29 16:54:37 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# define BUFF_SIZE 3000

# include <stdarg.h>
# include <inttypes.h>


typedef struct		s_printf
{
	int				before_len;
	int				before_arg_len;
	int				arg_len;
	int				location;
	int				write_size;
	int				return_val;
	void			*to_store;
	char			character;
	char 			type;
	char			modifier[3];
	char			sign[3];
	char			left_align_output;
	char			show_sign;
	char			sharp;
	int				width;
	int				precision;
}					t_printf;

char				*width_padding(char *printf_str, int int_nbr);
int					printf(const char *restrict format, ...);
char				char_type_add(char c);
int					ft_printf(const char *restrict format, ...);
t_printf			initialize_elem(void);
char 				*treat_and_store_argument(va_list ap, t_printf *argument,
		char *format);
char				*get_flags(t_printf *argument, char *format);
char				*get_precision(va_list ap, t_printf *argument, char *format);
char				*get_width(va_list ap, t_printf *argument, char *format);
char				*get_modifier(t_printf *argument, char *format);
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
void				store_print_handler(t_printf *argument, int location, int sizeof_var, int
		memset);
void				irrational_printf_changes(t_printf	*argument);
int					set_get_return(int action);

#endif
