#include "../includes/printf.h"
#include "../libft/includes/libft.h"

void		print_list(void)
{
	t_printf	*argument;

	argument = NULL;
	if (!(argument = set_get_arg_list(1)))
		(set_get_return((-1)));
	while (argument)
	{
		if (argument->before)
		{
			ft_putstr(argument->before);
			ft_putchar('\n');
		}
		if (argument->show_sign)
		{
			ft_putchar(argument->show_sign);
			ft_putchar('\n');
		}
		if (argument->left_align_output)
		{
			ft_putnbr(argument->left_align_output);
			ft_putchar('\n');
		}
		if (argument->width)
		{
			ft_putnbr(argument->width);
			ft_putchar('\n');
		}
		if (argument->precision)
		{
			ft_putnbr(argument->precision);
			ft_putchar('\n');
		}
		if (argument->type)
		{
			write(1, &(argument->type), 1);
			ft_putchar('\n');
		}
		if ((argument->modifier)[0])
		{
			ft_putstr(argument->modifier);
			ft_putchar('\n');
		}
		argument = argument->next;
	}
}

