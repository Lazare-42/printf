#include "../libft/includes/libft.h"
#include "../includes/printf.h"

/* 
 ** this function produces the string for the %p type
 ** FYI uintptr_t is the only type guaranteed to hold a pointer value
 */

void	get_hex_ptr_adr(va_list ap, char **argument)
{
	void	*test_data;
	char	*tmp;

	test_data = NULL;
	tmp = NULL;
	test_data = va_arg(ap, void*);
	if (!(*argument = ft_joinfree_heapstr_stackstr(argument, "0x", 'b')))
		return ;
	if (!(tmp = ft_s_base_converter(16, (uintptr_t)test_data)))
		return ;
	*argument = ft_strjoinfree(argument, &tmp, 'B');
}
