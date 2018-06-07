#include <stdlib.h>
#include "printf.h"
#include "../libft/includes/libft.h"

static t_printf	*new_list_element(void)
{
	t_printf *new_list_element;

	new_list_element = NULL;
	if (!(new_list_element = malloc(sizeof(t_printf))))
		return (ft_put_error_return_null("malloc error", "new_list_element"));
	new_list_element->arg = NULL;
	new_list_element->before = NULL;
	new_list_element->precision = 0;
	new_list_element->show_sign = 0;
	new_list_element->width_type = 0;
	new_list_element->left_align_output = 0;
	return (new_list_element);
}

t_printf		*set_get_arg_list(int get_first)
{
	static t_printf	*arg_list = NULL;
	t_printf		*tmp;
	t_printf		*new;

	tmp = NULL;
	new = NULL;
	if (!(arg_list))
	{
		if (!(arg_list = new_list_element()))
			return (NULL);
		else
			return (arg_list);
	}
	if (get_first)
		return (arg_list);
	tmp = arg_list;
	while (tmp->next)
		tmp = tmp->next;
	if (!(new = new_list_element()))
		return (NULL);
	else
		tmp->next = new;
	return (new);
}
