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
	/*
 ft_printf("%5%");                           
 printf("\n%5%");                           

 ft_printf("\n%-5%");                           
 printf("\n%-5%");                           

 ft_printf("%.0%");                           
 printf("\n%.0%");                           

 ft_printf("%   %", "test");                  
 printf("%   %", "test");                  

 ft_printf("%010x", 542);                     
 printf("\n%010x", 542);                     

 ft_printf("%#8x", 42);                       
 printf("\n%#8x", 42);                       

 ft_printf("%#08x", 42);                      
 printf("\n%#08x", 42);                      

 ft_printf("%#-08x", 42);                     
 printf("\n%#-08x", 42);                     

 ft_printf("%#08x", 42);                      
 printf("\n%#08x", 42);                      

 ft_printf("%#-08x", 42);                     
 printf("\n%#-08x", 42);                     
 */
 
 ft_printf("@moulitest: %#.x %#.0x", 0, 0);   
 printf("\n@moulitest: %#.x %#.0x", 0, 0);   

 ft_printf("@moulitest: %#.x %#.0x", 0, 0);   
 printf("\n@moulitest: %#.x %#.0x", 0, 0);   

 ft_printf("%-.2s is a string", "this");      
 printf("\n%-.2s is a string", "this");      
 ft_printf("\n%-5.2s is a string", "this");     
 printf("\n%-5.2s is a string", "this");     

 ft_printf("@moulitest: %s", NULL);           
 printf("\n@moulitest: %s", NULL);           

 ft_printf("@moulitest: %c", 0);              
 printf("\n@moulitest: %c", 0);              
 /*
 ft_printf("%2c", 0);                         
 ft_printf("null %c and text", 0);            
 ft_printf("% c", 0);                         
 ft_printf("%#6o", 2500);                     
 ft_printf("%-#6o", 2500);                    
 ft_printf("%-05o", 2500);                    
 ft_printf("%-5.10o", 2500);                  
 ft_printf("%-10.5o", 2500);                  
 ft_printf("%+ d", 42);                       
 ft_printf("%+  d", 42);                      
 ft_printf("%++ d", 42);                      
 ft_printf("%0d", -42);                       
 ft_printf("%00d", -42);                      
 ft_printf("%0+5d", 42);                      
 ft_printf("%05d", -42);                      
 ft_printf("%0+5d", -42);                     
 ft_printf("%-05d", 42);                      
 ft_printf("%-05d", -42);                     
 ft_printf("%hd", 32768);                     
 ft_printf("%hhd", 128);                      
 ft_printf("%hhd", -129);                     
 ft_printf("%ld", 2147483648);                
 ft_printf("%ld", -2147483649);               
 ft_printf("%lld", 9223372036854775807);      
 ft_printf("%jd", 9223372036854775807);       
 ft_printf("%zd", 4294967295);                
 ft_printf("%zd", 4294967296);                
 ft_printf("%-10.5d", 4242);                  
 ft_printf("% 10.5d", 4242);                  
 ft_printf("%+10.5d", 4242);                  
 ft_printf("%-+10.5d", 4242);                 
 ft_printf("%03.2d", 0);                      
 ft_printf("%03.2d", 1);                      
 ft_printf("%03.2d", -1);                     
 ft_printf("@moulitest: %.10d", -42);         
 ft_printf("% u", 4294967295);                
 ft_printf("%+u", 4294967295);                
 */

}
