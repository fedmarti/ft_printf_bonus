/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:11:36 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 17:42:00 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	len_meas_b(int *l, unsigned long *p, unsigned long n, int base)
{
	unsigned long long int	pow;

	pow = 1;
	while (n / pow >= (unsigned long) base)
	{
		*l = *l + 1;
		pow = pow * base;
	}
	*p = pow;
	if (n == 0)
		*l = 1;
	else
		*l = *l + 1;
}

char	*ft_ultoa_base(unsigned long n, char *base)
{
	unsigned int		radix;
	char				*num;
	int					len;
	unsigned long int	pow;
	int					i;

	radix = ft_strlen(base);
	len = 0;
	len_meas_b(&len, &pow, n, radix);
	num = malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	i = 0;
	while (pow > 0)
	{
		num[i] = base[n / pow % radix];
		pow /= radix;
		i++;
	}
	num[len] = 0;
	return (num);
}
