#include <stdio.h>
#include "includes/libft.h"
#include "includes/printf.h"
#include <stdlib.h>
#include <limits.h>
#include <locale.h>

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

#include <math.h>

int main()
{
	setlocale(LC_ALL, ""); int ret; int test = 420; 
(void)test;



/*
	ret = ft_printf("% h");
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("% h");
	printf("\nret = %d\n", ret); fflush(stdout);
	*/

ret =   ft_printf("%");                               
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("% ");                              
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("% h");                             
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%Z");                              
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("% hZ");                            
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%05%");                            
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%-05%");                           
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("% hZ%"); 
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("% Z", "test");                     
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("% Z ", "test");                    
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("% Z%s", "test");                   
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%000   %", "test");                
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%%%", "test");                     
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%%   %", "test");                  
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%ll#x", 9223372036854775807);      
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%010s is a string", "this");       
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%-010s is a string", "this");      
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%05c", 42);                        
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("% Z", 42);                         
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%0 d", 42);                        
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%0 d", -42);                       
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("% 0d", 42);                        
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("% 0d", -42);                       
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%5+d", 42);                        
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%5+d", -42);                       
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%-5+d", 42);                       
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%-0+5d", 42);                      
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%-5+d", -42);                      
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%-0+5d", -42);                     
printf("\nret = %d\n", ret); fflush(stdout);
ret =   ft_printf("%zhd", 4294967296);                
printf("\nret = %d\n", ret); fflush(stdout);

 ret =  ft_printf("%jzd", 9223372036854775807);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  ft_printf("%jhd", 9223372036854775807);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  ft_printf("%lhl", 9223372036854775807);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  ft_printf("%lhlz", 9223372036854775807);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  ft_printf("%zj", 9223372036854775807);  
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  ft_printf("%lhh", 2147483647);         
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  ft_printf("%hhld", 128);              
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  ft_printf("@main_ftprintf: %####0000 33..1d", 256);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
printf("\nret = %d\n", ret); fflush(stdout);


/*
ret =   ft_printf("%-15x", 542);
ret =   ft_printf("%2x", 542);
ret =   ft_printf("%.2x", 5427);
	ret = ft_printf("toto%.0d et %+.d", 0, 1);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("toto%.0d et %+.d", 0, 1);
	printf("\nret = %d\n", ret); fflush(stdout);
   * 
	ret = ft_printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	ret = ft_printf("coco et %-#-#--24O titi%#012o", 12, -874);
	ret = ft_printf("\n%024hho et%#1.2o %0012.O", (unsigned char)12, 0, 123654789);
	ret = ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	ret = ft_printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
	ret = ft_printf("%0#10.0x %0#x", 12345, 0);
	ret = ft_printf("%0#10.0x", 0);
  */
ret =   printf("%");                               
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("% ");                              
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("% h");                             
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%Z");                              
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("% hZ");                            
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%05%");                            
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%-05%");                           
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("% hZ%"); 
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("% Z", "test");                     
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("% Z ", "test");                    
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("% Z%s", "test");                   
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%000   %", "test");                
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%%%", "test");                     
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%%   %", "test");                  
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%ll#x", 9223372036854775807);      
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%010s is a string", "this");       
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%-010s is a string", "this");      
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%05c", 42);                        
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("% Z", 42);                         
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%0 d", 42);                        
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%0 d", -42);                       
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("% 0d", 42);                        
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("% 0d", -42);                       
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%5+d", 42);                        
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%5+d", -42);                       
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%-5+d", 42);                       
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%-0+5d", 42);                      
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%-5+d", -42);                      
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%-0+5d", -42);                     
printf("\nret = %d\n", ret); fflush(stdout);
ret =   printf("%zhd", 4294967296);                
printf("\nret = %d\n", ret); fflush(stdout);

 ret =  printf("%jzd", 9223372036854775807);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("%jhd", 9223372036854775807);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("%lhl", 9223372036854775807);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("%lhlz", 9223372036854775807);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("%zj", 9223372036854775807);  
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("%lhh", 2147483647);         
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("%hhld", 128);              
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("@main_ftprintf: %####0000 33..1d", 256);
printf("\nret = %d\n", ret); fflush(stdout);
 ret =  printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256);
printf("\nret = %d\n", ret); fflush(stdout);


/*
ret =   ft_printf("%-15x", 542);
ret =   ft_printf("%2x", 542);
ret =   ft_printf("%.2x", 5427);
	ret = ft_printf("toto%.0d et %+.d", 0, 1);
	printf("\nret = %d\n", ret); fflush(stdout);
	ret = printf("toto%.0d et %+.d", 0, 1);
	printf("\nret = %d\n", ret); fflush(stdout);
   * 
	ret = ft_printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0);
	ret = ft_printf("coco et %-#-#--24O titi%#012o", 12, -874);
	ret = ft_printf("\n%024hho et%#1.2o %0012.O", (unsigned char)12, 0, 123654789);
	ret = ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499);
	ret = ft_printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0);
	ret = ft_printf("%0#10.0x %0#x", 12345, 0);
	ret = ft_printf("%0#10.0x", 0);
  */


}
