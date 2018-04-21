int	set_get_precision(int yes)
{
	static char answer = 0;

	if (yes)
		answer = 1;
	return (answer);
}
