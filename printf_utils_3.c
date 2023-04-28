/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:12:06 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 17:21:48 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const	char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

static int	print_zero_padding(char *str, t_flags *flag)
{
	int	len;

	len = 0;
	if (*str == '-' || *str == '+' || *str == ' ')
	{
		len += ft_putchar(*str);
	}
	else if (flag->hex_prefix)
	{
		len += ft_putchar(*str);
		str++;
		len += ft_putchar(*str);
	}
	return (len);
}

int	handle_padding(char *str, t_flags *flag)
{
	int		len;
	int		content_len;
	char	padding;

	len = 0;
	content_len = ft_strlen(str);
	padding = ' ';
	if (flag->left_justify)
		len += ft_putstr(str);
	if (flag->zero_padding)
	{
		padding = '0';
		len = print_zero_padding(str, flag);
		content_len -= len;
		str += len;
	}
	while (len + (content_len * (!flag->left_justify)) < flag->width)
		len += ft_putchar(padding);
	if (!flag->left_justify)
		len += ft_putstr(str);
	return (len);
}
