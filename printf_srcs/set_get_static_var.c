/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get_static_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazrossi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:29:52 by lazrossi          #+#    #+#             */
/*   Updated: 2018/06/25 09:30:14 by lazrossi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		set_get_precision(int yes)
{
	static char answer = 0;

	if (yes)
		answer = 1;
	return (answer);
}

char	char_type_add(char c)
{
	static char ret = 0;

	if (c)
		ret = c;
	return (ret);
}

int		set_get_return(int value)
{
	static int return_val = 0;

	if (return_val == -1)
		return (-1);
	if (!value)
		return (return_val);
	if (value == -1)
		return_val = -1;
	else
		return_val += value;
	return (return_val);
}

char	set_get_flags_presence(int yes)
{
	static char presence = 0;

	if (!yes)
		return (presence);
	else
		(presence = 1);
	return (presence);
}
