/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:23:42 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/01 19:08:30 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (str)
	{
		len = ft_strlen(str);
		write(1, str, len * sizeof(char));
	}
	else
		ft_putchar('\0');
	return (len);
}

int	ft_put_u(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_put_u(n / 10);
		n %= 10;
	}
	len += ft_putchar("0123456789"[n]);
	return (len);
}

int	ft_put_d(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	len += ft_put_u(n);
	return (len);
}

int	ft_puthex(size_t n, char flag)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex(n / 16, flag);
		n %= 16;
	}
	if (n < 10)
		len += ft_putchar("0123456789"[n]);
	else
		len += ft_putchar(flag - 33 + n);
	return (len);
}

int	ft_put_p(void *p)
{
	int	len;

	if (p)
	{
		len = ft_putstr("0x");
		len += ft_puthex((long unsigned int)p, 'x');
	}
	else
		len = ft_putstr("(nil)");
	return (len);
}
