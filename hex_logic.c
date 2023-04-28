/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_logic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:06:40 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 17:55:13 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_x_prefix(char	*src, char c)
{
	char	prefix[3];
	char	*str;

	prefix[0] = '0';
	prefix[1] = c;
	prefix[2] = 0;
	str = ft_strjoin(prefix, src);
	free(src);
	return (str);
}

static char	*itoa_hex(unsigned int n, char flag)
{
	char	*num;

	if (flag == 'X')
		num = ft_utoa_base(n, "0123456789ABCDEF");
	else
		num = ft_utoa_base(n, "0123456789abcdef");
	return (num);
}

int	print_hex(unsigned int n, t_flags *flag)
{
	int		len;
	char	*num;

	num = itoa_hex(n, flag->type);
	if (!num)
		return (0);
	if (flag->precision > ft_strlen(num))
	{
		num = handle_precision(num, flag);
		if (!num)
			return (0);
	}
	if (flag->hex_prefix && n)
	{
		num = add_x_prefix(num, flag->type);
		if (!num)
			return (0);
	}
	if (flag->precision == 0 && n == 0)
		num[0] = 0;
	len = handle_padding(num, flag);
	free(num);
	return (len);
}
