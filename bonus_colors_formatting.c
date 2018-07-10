#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define BLD	  "\x1B[1m"
#define ITA	  "\x1B[3m"
#define BLK   "\x1B[6m"
#define SBLK   "\x1B[5m"
#define SWP   "\x1B[7m"
#define UND   "\x1B[4m"
#define FRM   "\x1B[51m"
#define BCK	  "\x1B[40m"
#define RESET "\x1B[0m"

#include "../includes/libft.h"
#include "../includes/printf.h"

void	help(void)
{
	ft_putstr("Available formatting options for ");
	terminal_formatting("[[blue]][[underline]][[bold]][[italic]][[swapp]]");
	ft_putstr("lazrossi's fr_printf");
	terminal_formatting("[[end]]");
	ft_putstr(" are :\n");
	ft_putstr(terminal_formatting("[[red]]red,\n"));
	ft_putstr(terminal_formatting("[[green]]green,\n"));
	ft_putstr(terminal_formatting("[[yellow]]yellow,\n"));
	ft_putstr(terminal_formatting("[[blue]]blue,\n"));
	ft_putstr(terminal_formatting("[[magenta]]magenta,\n"));
	ft_putstr(terminal_formatting("[[cyan]]cyan,\n"));
	ft_putstr(terminal_formatting("[[white]]white,\n"));
	ft_putstr(terminal_formatting("[[bold]]bold,\n"));
	ft_putstr(terminal_formatting("[[end]][[italic]]italic,\n"));
	ft_putstr(terminal_formatting("[[end]][[blink]]blink,\n"));
	ft_putstr(terminal_formatting("[[end]][[frame]]frame,\n"));
	ft_putstr(terminal_formatting("[[end]][[background]]setting background"));
	ft_putstr(" color\n");
	ft_putstr(terminal_formatting("[[end]][[underline]]underline"));
	ft_putstr(terminal_formatting("[[end]],\n"));
	ft_putstr(terminal_formatting("[[swapp]]swapping foreground and backgrou"));
	ft_putstr(terminal_formatting("nd."));
	ft_putstr(terminal_formatting("[[end]]"));
}

char		*continue_font_formatting(char *format)
{
	if (!(ft_strncmp(format, "[[frame]]", 9)))
	{
		ft_putstr(FRM);
		format += 9;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[background]]", 14)))
	{
		ft_putstr(BCK);
		format += 14;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[underline]]", 13)))
	{
		ft_putstr(UND);
		format += 13;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[swapp]]", 9)))
	{
		ft_putstr(SWP);
		format += 9;
		return (terminal_formatting(format));
	}
	return (format);
}

char		*font_formatting(char *format)
{
	if (!(ft_strncmp(format, "[[bold]]", 8)))
	{
		ft_putstr(BLD);
		format += 8;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[end]]", 7)))
	{
		ft_putstr(RESET);
		format += 7;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[italic]]", 10)))
	{
		ft_putstr(ITA);
		format += 10;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[blink]]", 9)))
	{
		ft_putstr(BLK);
		format += 9;
		return (terminal_formatting(format));
	}
	return (format = continue_font_formatting(format));
}

char		*continue_color_formatting(char *format)
{
	if (!(ft_strncmp(format, "[[blue]]", 8)))
	{
		ft_putstr(BLU);
		format += 8;
		return (terminal_formatting(format));
	}
	if (!(ft_strncmp(format, "[[magenta]]", 11)))
	{
		ft_putstr(MAG);
		format += 11;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[cyan]]", 8)))
	{
		ft_putstr(CYN);
		format += 8;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[white]]", 9)))
	{
		ft_putstr(WHT);
		format += 9;
		return (terminal_formatting(format));
	}
	return (format = font_formatting(format));
}

char		*terminal_formatting(char *format)
{
	if (!(ft_strncmp(format, "[[red]]", 7)))
	{
		ft_putstr(RED);
		format += 7;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[green]]", 9)))
	{
		ft_putstr(GRN);
		format += 9;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[yellow]]", 10)))
	{
		ft_putstr(YEL);
		format += 10;
		return (terminal_formatting(format));
	}
	else if (!(ft_strncmp(format, "[[help?]]", 9)))
	{
		help();
		return (NULL);
	}
	return (format = continue_color_formatting(format));
}
