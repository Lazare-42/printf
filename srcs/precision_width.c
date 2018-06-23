#include "../libft/includes/libft.h"
#include "../includes/printf.h"

// il faudrait liberer argument->width dans les cas ou il a ete malloc
// et pas recuperer avec va_list 
// a faire dans la fonction de liberation finale
// aussi a y faire : ft_memdel((void**)&(argument)->arg);

static	t_printf	*apply_width(t_printf *argument)
{
	char	*tmp;
	int		strlen;

	tmp = NULL;
	strlen = 0;
	if (argument->arg)
		strlen = ft_strlen((argument)->arg);
	if (strlen < (argument)->width)
	{
		tmp = ft_strnew((argument)->width);
		ft_memset(tmp, ' ', (argument)->width - strlen);
		(argument->arg) ? tmp = ft_strcat(tmp, (argument)->arg) : 0;
		(argument)->arg = tmp;
	}
	return (argument);
}

static 	t_printf	*apply_flag_padding(t_printf *argument)
{
	char	*tmp;
	int		strlen;

	tmp = NULL;
	strlen = ft_strlen((argument)->arg);
	if (strlen < (argument)->width && (argument)->left_align_output == 1)
	{
		tmp = ft_strnew((argument)->width);
		ft_memcpy(tmp, (argument)->arg, strlen);
		ft_memset(tmp + strlen, ' ', (argument)->width - strlen);
	}
	else if (strlen < (argument)->width && !((argument)->left_align_output))
	{
		tmp = ft_strnew((argument)->width);
		ft_memset(tmp, '0', (argument)->width - strlen);
		tmp = ft_strcat(tmp, (argument)->arg);
	}
	ft_memdel((void**)&((argument)->arg));
	(argument)->arg = tmp;
	return (argument);
}

static	t_printf	*apply_plus_minus_flags(t_printf *argument)
{
	if ((argument)->show_sign == ' ' && *((argument)->arg) != '-')
		(argument)->arg = ft_strjoinfree_char_str(' ', &(argument)->arg);
	else if ((argument)->show_sign == '+' && *((argument)->arg) != '-')
		(argument)->arg = ft_strjoinfree_char_str('+', &(argument)->arg);
	return (argument);
}

static	t_printf	*apply_precision(t_printf *argument)
{
	int		strlen;
	char	*tmp;
	int		i;

	strlen = ft_strlen(argument->arg);
	tmp = NULL;
	i = 0;
	if (ft_strchr("diouxX", argument->type) && argument->precision > strlen)
	{
		tmp = ft_strnew(argument->precision);
		ft_memset(tmp, '0', argument->precision - strlen);
		tmp = ft_strcat(tmp, argument->arg);
		ft_memdel((void**)&(argument->arg));
		(argument)->arg = tmp;
	}
	(!argument->precision && ft_strchr("diouxX", argument->type)
			&& *argument->arg == '0') ? ft_memdel((void*)&(argument->arg)): 0;
	if (!argument->precision && argument->type == 's')
		ft_memdel((void*)&(argument->arg));
	else if (argument->type == 's')
		argument->arg = ft_strndup_free(&(argument->arg), argument->precision);
	return (argument);
}

t_printf		*apply_precision_width(t_printf *argument)
{
	if (!(argument)->arg)
	{
		set_get_return(-1);
		return (NULL);
	}
	if (argument->show_sign)
		argument = apply_plus_minus_flags(argument);
	if (argument->left_align_output != -1)
		argument = apply_flag_padding(argument);
	if (argument->precision != -1)
		argument = apply_precision(argument);
	if (argument->width)
		argument = apply_width(argument);
	return (argument);
}
