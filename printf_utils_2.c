/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:20:53 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 18:30:39 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_alpha(char c)
{
	return (('a' <= c && 'z' >= c) || ('A' <= c && 'Z' >= c));
}

bool	is_num(char c)
{
	return (('0' <= c && '9' >= c));
}

int	ft_atoui(char *str)
{
	int	n;

	n = 0;
	while (is_num(*str))
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (n);
}

// takes one int as the goal and looks through the 0 terminated list of args
// returns true if it finds it
bool	in(int goal, ...)
{
	va_list	args;
	int		arg;
	bool	found;

	found = false;
	va_start(args, goal);
	arg = va_arg(args, int);
	while (!found && arg)
	{
		if (arg == goal)
			found = true;
		arg = va_arg(args, int);
	}
	va_end(args);
	return (found);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		tot_len;
	int		i;
	char	*dest;

	tot_len = ft_strlen(s1);
	tot_len += ft_strlen(s2);
	dest = malloc((tot_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (*s1 && i < tot_len)
	{
		dest[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 && i < tot_len)
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	dest[i] = 0;
	return (dest);
}
