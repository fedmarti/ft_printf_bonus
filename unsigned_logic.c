/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_logic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:58:05 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 18:02:23 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n, t_flags *flag)
{
	int		len;
	char	*num;

	num = ft_utoa_base(n, "0123456789");
	if (!num)
		return (0);
	if (flag->precision > ft_strlen(num))
	{
		num = handle_precision(num, flag);
		if (!num)
			return (0);
	}
	else if (flag->precision == 0 && n == 0)
		num[0] = 0;
	len = handle_padding(num, flag);
	free(num);
	return (len);
}
