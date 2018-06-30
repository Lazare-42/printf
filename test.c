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

//ft_printf("\n\n\n%08x", 42);                       
int main()
{

ft_printf("vvsdfdfdflkjnvn%#21s coucou", "HI");                      
//printf("\n%#21x coucou", 4);                      
/*
ft_printf("\n@moulitest: %s", NULL);            
ft_printf("\n%.2c", NULL);                      
ft_printf("\n%s %s", NULL, string);             
ft_printf("\n%c", 42);                          
ft_printf("\n%5c", 42);                         
ft_printf("\n%-5c", 42);                        
ft_printf("\n@moulitest: %c", 0);               
ft_printf("\n%2c", 0);                          
ft_printf("\nnull %c and text", 0);             
ft_printf("\n% c", 0);                          
ft_printf("\n%05o", 42);                        
ft_printf("\n%#6o", 2500);                      
ft_printf("\n%-#6o", 2500);                     
ft_printf("\n%-5.10o", 2500);                   
ft_printf("\n%-10.5o", 2500);                   
ft_printf("\n@moulitest: %o", 0);               
ft_printf("\n@moulitest: %#.o %#.0o", 0, 0);    
ft_printf("\n%d", -1);                          
ft_printf("\n%d", -4242);                       
ft_printf("\n%d", 2147483648);                  
ft_printf("\n%d", -2147483648);                 
ft_printf("\n% d", 42);                         
ft_printf("\n%+d", 42);                         
ft_printf("\n%+d", 0);                          
ft_printf("\n% +d", 42);                        
ft_printf("\n%+ d", 42);                        
ft_printf("\n%  +d", 42);                       
ft_printf("\n%+  d", 42);                       
ft_printf("\n% ++d", 42);                       
ft_printf("\n%++ d", 42);                       
ft_printf("\n%0d", -42);                        
ft_printf("\n%00d", -42);                       
ft_printf("\n%05d", 42);                        
ft_printf("\n%0+5d", 42);                       
ft_printf("\n%5d", -42);                        
ft_printf("\n%05d", -42);                       
ft_printf("\n%0+5d", -42);                      
ft_printf("\n%-5d", -42);                       
ft_printf("\n%-05d", -42);                      
ft_printf("\n%hd", −32768);                   
ft_printf("\n%hd", 32768);                      
ft_printf("\n%hd", −32769);                   
ft_printf("\n%hhd", 128);                       
ft_printf("\n%hhd", -128);                      
ft_printf("\n%ld", -2147483648);                
ft_printf("\n%ld", -2147483649);                
ft_printf("\n%lld", -9223372036854775808);      
ft_printf("\n%jd", -9223372036854775808);       
ft_printf("\n%zd", -0);                         
ft_printf("\n%zd", -1);                         
ft_printf("\n%d %d", 1, -2);                    
ft_printf("\n%d %d %d", 1, -2, 33);             
ft_printf("\n%d %d %d %d", 1, -2, 33, 42);      
ft_printf("\n%d %d %d %d gg!", 1, -2, 33, 42, 0); 
ft_printf("\n%4.15d", 42);                      
ft_printf("\n%10.5d", 4242);                    
ft_printf("\n%-10.5d", 4242);                   
ft_printf("\n% 10.5d", 4242);                   
ft_printf("\n%+10.5d", 4242);                   
ft_printf("\n%-+10.5d", 4242);                  
ft_printf("\n%03.2d", 0);                       
ft_printf("\n%03.2d", 1);                       
ft_printf("\n%03.2d", -1);                      
ft_printf("\n@moulitest: %.10d", -42);          
ft_printf("\n%u", 4294967296);                  
ft_printf("\n%015u", 4294967295);               
ft_printf("\n\n%jd", -9223372036854775808);       
ft_printf("\n\n%   %", "test");                   
*/
}
