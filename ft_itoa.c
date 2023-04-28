/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:49:38 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 16:07:13 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	init_len_sign(long *n, int *len, int *sign)
{
	if (*n < 0)
	{
		*sign = -1;
		*len = 1;
		*n *= -1;
	}
	else
	{
		*sign = 1;
		*len = 0;
	}
}

static void	len_measure(int *len, int *pow, long n)
{
	*pow = 1;
	while ((long)(*pow) *10 <= n)
	{
		*len = *len + 1;
		*pow = *pow * 10;
	}
	*len = *len + 1;
	if (n == 0)
		*len = 1;
}

char	*ft_itoa(long n)
{
	char	*num;
	int		len;
	int		pow;
	int		sign;
	int		i;

	init_len_sign(&n, &len, &sign);
	len_measure(&len, &pow, n);
	num = malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	i = 0;
	if (sign < 0)
	{
		i++;
		*num = '-';
	}
	while (pow > 0)
	{
		num[i] = n / pow % 10 + '0';
		pow /= 10;
		i++;
	}
	num[len] = 0;
	return (num);
}
