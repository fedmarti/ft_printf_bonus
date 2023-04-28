/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:15:00 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 18:07:17 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_char(char c, t_flags *flags)
{
	int		len;
	char	str[2];

	len = 0;
	if (!c)
	{
		if (flags->width)
			flags->width--;
		if (flags->left_justify)
			len += ft_putchar(c);
	}
	str[0] = c;
	str[1] = 0;
	len += handle_padding(str, flags);
	if (!flags->left_justify && !c)
		len += ft_putchar(c);
	return (len);
}

int	print_arg(va_list args, t_flags *flags)
{
	if (flags->type == 'c')
		return (print_char(va_arg(args, int), flags));
	else if (flags->type == 's')
		return (print_str(va_arg(args, char *), flags));
	else if (flags->type == 'p')
		return (print_pointer(va_arg(args, void *), flags));
	else if (flags->type == 'd' || flags->type == 'i')
		return (print_int(va_arg(args, int), flags));
	else if (flags->type == 'u')
		return (print_unsigned(va_arg(args, unsigned int), flags));
	else if (flags->type == 'x' || flags->type == 'X')
		return (print_hex(va_arg(args, unsigned int), flags));
	else if (flags->type == '%')
		return (ft_putchar(flags->type));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flags	*flag;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
			len += ft_putchar(*str);
		else
		{
			flag = get_flags(str);
			if (!flag)
				break ;
			len += print_arg(args, flag);
			str += flag->offset;
			free (flag);
			flag = NULL;
		}
		str++;
	}
	va_end(args);
	return (len);
}
