#include "../includes/printf.h"
#include "../includes/libft.h"
#include <unistd.h>
#include <fcntl.h>

int		set_get_fd(int action)
{
	static int fd = 1;

	if (!action)
		return (fd);
	else
		fd = action;
	return (action);
}

const char	*continue_setting_fd(const char *format, int no_append)
{
	int i;
	int		o_flag;
	char	path[2049];
	int		fd;

	i = 0;
	fd = 0;
	ft_memset(path, 0, 2049);
	o_flag = O_RDWR | O_CREAT;
	o_flag |= (no_append) ?  0 : O_APPEND;
	if (!(ft_strncmp(format, "[[./", 4)))
	{
		while (*format && *format != ']')
		{
			ft_memcpy(path + i, format, 1);
			i++;
			format++;
		}
		format += 2;
		set_get_fd(open(path, o_flag));
	}
	return (format);
}

const char	*choose_set_file_descriptor(const char *format, t_str *argument)
{
	int		no_append;

	no_append = 0;
	launch_string_print(NULL, 0, argument, 1);
	if (set_get_fd(0) != '1')
		close(set_get_fd(0));
	if (!(ft_strncmp(format, "[[fd=", 5)))
	{
		format += 5;
		set_get_fd(ft_atoi(format));
		while (*format && *format != ']')
			format++;
		if (*format && *format == ']')
			format++;
	}
	if (!ft_strncmp(format, "[[no_append]]", 13))
	{
		format += 13;
		no_append = 1;
	}
	return (continue_setting_fd(format, no_append)); 
}

