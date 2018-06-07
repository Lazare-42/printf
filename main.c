#include <stdio.h>
#include <stdlib.h>
#include "./libft/includes/libft.h"

/*
   char	*hexadecimal_string(char c)
   {
   static char *string = NULL;

   if (c && string)
   return (string = ft_strjoinfree_char_str(c, &string));
   else if (c)
   {
   if (!(string = malloc(sizeof(char) * 1)))
   ft_myexit("malloc error");
   else
 *string = c;
 }
 return (string);
 }

 void	hexa_conversion(int argument)
 {
 char hexa[17] = "01234567890abcdef";

 hexadecimal_string(hexa[argument % 16]);
 if (argument / 16)
 hexa_conversion(argument / 16);
 }
 */

int main(int ac, char **av)
{
	(void)ac;
	double integer;
	if (av[1])
		integer = ft_atof(av[1]);
	else
		integer = 0;
	printf("%*.*g\n hi my name is lazare \n %*.*g\n", 9, 10, integer, 9, 10, integer);
	//	ft_ftoa(integer);
	//	printf("%f\n", integer);
	//	hexa_conversion(integer);
	//	ft_putstr(hexadecimal_string(0));
}

/*
   printf("\nret : %d\n", 	   printf("PR %%d : %d", 19));
   printf("\nret : %010d\n", 	   printf("PR %%d : %d", 19));
   printf("\nret : %d\n", 	   printf("PR %%D : %D", 19));		
   printf("\nret : %d\n", 	   printf("PR %%i : %i", 19));
   printf("\nret : %d\n", 	   printf("PR %%o : %o", 19));
   printf("\nret : %d\n", 	   printf("PR %%O : %O", 19));
   printf("\nret : %d\n", 	   printf("PR %%u : %u", 19));
   printf("\nret : %d\n", 	   printf("PR %%U : %U", 19));
   printf("\nret : %d\n", 	   printf("PR %%x : %x", 19));
   printf("\nret : %d\n", 	   printf("PR %%X : %X", 19));
 */
