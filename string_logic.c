/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:36:51 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 17:59:30 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(src);
	if (len > n)
		len = n;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= len)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

int	print_str(char *str, t_flags *flag)
{
	int		len;
	char	*dest;

	if (!str || !flag->precision)
	{
		if (flag->precision < 6)
			len = handle_padding("", flag);
		else
			len = handle_padding("(null)", flag);
	}
	else
	{
		dest = ft_strndup(str, flag->precision);
		if (!dest)
			return (0);
		len = handle_padding(dest, flag);
		free (dest);
	}
	return (len);
}
