/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:15:55 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 18:28:16 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *p, t_flags *flag)
{
	char	*addr;
	char	*temp;
	int		len;

	if (!p)
		len = handle_padding("(nil)", flag);
	else
	{
		temp = ft_ultoa_base((long unsigned int)p, "0123456789abcdef");
		if (!temp)
			return (0);
		addr = ft_strjoin("0x", temp);
		free(temp);
		if (!addr)
			return (0);
		len = handle_padding(addr, flag);
		free(addr);
	}
	return (len);
}

void	fill_zeros_and_copy(char *num, t_flags *flag, char *temp, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (temp[i] == '-')
	{
		num[i] = temp[j];
		i++;
		j++;
	}
	while (i - (2 * j) < flag->precision - len)
	{
		num[i] = '0';
		i++;
	}
	while (temp[j])
	{
		num[i] = temp[j];
		i++;
		j++;
	}
	num[i] = 0;
	free(temp);
}

char	*handle_precision(char	*num, t_flags *flag)
{
	char	*temp;
	int		len;

	len = ft_strlen(num);
	temp = num;
	num = malloc((flag->precision + (*num == '-') + 1) * sizeof(char));
	if (!num)
	{
		free (temp);
		return (NULL);
	}
	fill_zeros_and_copy(num, flag, temp, len);
	return (num);
}

char	*handle_sign(char *num, t_flags *flag)
{
	char	*temp;
	char	sign[2];

	temp = num;
	if (flag->sign == Plus)
		sign[0] = '+';
	else
		sign[0] = ' ';
	sign[1] = 0;
	num = ft_strjoin(sign, temp);
	free(temp);
	return (num);
}

int	print_int(int n, t_flags *flag)
{
	int		len;
	char	*num;

	num = ft_itoa((long)n);
	if (!num)
		return (0);
	if (flag->precision > ft_strlen(num) - (*num == '-'))
	{
		num = handle_precision(num, flag);
		if (!num)
			return (0);
	}
	else if (flag->precision == 0 && n == 0)
		num[0] = 0;
	if (flag->sign != Default && n >= 0)
	{
		num = handle_sign(num, flag);
		if (!num)
			return (0);
	}
	len = handle_padding(num, flag);
	free(num);
	return (len);
}
