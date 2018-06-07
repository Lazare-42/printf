char	char_type_add(char c)
{
	static char ret = 0;

	if (c)
		ret = c;
	return (ret);
}
