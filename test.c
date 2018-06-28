#include <stdio.h>
#include "includes/libft.h"
#include "includes/printf.h"
#include <stdlib.h>

char	*print_bits(void *ptr, int size) 
{
	int i;
	int bit_nbr = 0;
	char *result;
	char *test;
	int		j;

	i = 7;
	j = 0;
	test = ptr;
	if (!(result = ft_strnew(size * 10)))
		return (NULL);
	while (j < size)
	{
		result[bit_nbr] = (test[j] & (1 << i)) ? '1' : '0';
		bit_nbr++;
		(i == 4) ? result[bit_nbr] = ' ' : 0;
		(i == 4) ? bit_nbr++ : 0;
		(i == 0) ? result[bit_nbr] = ' ' : 0;
		(i == 0) ? j++ : 0;
		(i == 0) ? bit_nbr++ : 0;
		(i == 0) ? i = 8 : 0;
		i--;
	}
	return (result);
}

int main()
{
	//
ft_printf("\n% .5d", 4242);                  
printf("\n% .5d", 4242);                  
	/*

ft_printf("\n%+10.5d", 4242);                  
ft_printf("\n%-+10.5d", 4242);                 
ft_printf("\n%03.2d", 0);                      
ft_printf("\n%03.2d", 1);                      
ft_printf("\n%03.2d", -1);                     
ft_printf("\n@moulitest: %.10d", -42);        
ft_printf("\n% u", 4294967295);                
ft_printf("\n%+u", 4294967295);                

ft_printf("\n%jd", (uintmax_t)-9223372036854775808);    
printf("\n%jd", (uintmax_t)-9223372036854775808);    
*/
}
