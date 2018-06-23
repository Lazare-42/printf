#include "../includes/printf.h"
#include "../libft/includes/libft.h"

int		print_list(void)
{
	t_printf	*argument;
	char		*print;

	argument = NULL;
	print = NULL;
	if (!(argument = set_get_arg_list(1)))
		return (-1);
	while (argument)
	{
		if (argument->before)
			if (!(print = ft_strjoinfree(&print, &(argument->before), 'B')))
				return (set_get_return(-1));
		if (argument->arg)
			if (!(print = ft_strjoinfree(&print, &(argument->arg), 'B')))
				return (set_get_return(-1));
		(argument->before) ? ft_memdel((void*)&(argument->before)) : 0;
		(argument->arg) ? ft_memdel((void*)&(argument->before)) : 0;
		argument = argument->next;
	}
	set_get_arg_list(-1);
	return (write(1, print, ft_strlen(print)));
}

