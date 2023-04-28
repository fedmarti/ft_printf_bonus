/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:57:54 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 18:05:57 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*flag_init(void)
{
	t_flags	*flag;

	flag = malloc(sizeof(struct s_flags));
	if (!flag)
		return (NULL);
	flag->hex_prefix = false;
	flag->left_justify = false;
	flag->offset = 1;
	flag->precision = -1;
	flag->sign = Default;
	flag->type = 0;
	flag->width = 0;
	flag->zero_padding = false;
	return (flag);
}

static void	conflict_check(t_flags *flag)
{
	if (flag->zero_padding)
	{
		if (!in(flag->type, 'i', 'd', 'x', 'X', 'u', 0) || flag->precision >= 0
			|| flag->left_justify)
			flag->zero_padding = false;
	}
	if (flag->type == 's' && flag->precision < 0)
		flag->precision = __INT32_MAX__;
	if (flag->type != 'X' && flag->type != 'x')
		flag->hex_prefix = false;
	if (flag->type != 'i' && flag->type != 'd')
		flag->sign = Default;
}

static void	fucc_norminette(t_flags *flag, const char *str)
{
	if (str[flag->offset] == '0')
		flag->zero_padding = true;
	else if (is_num(str[flag->offset]))
	{
		flag->width = ft_atoui((char *)&str[flag->offset]);
		while (is_num(str[flag->offset + 1]))
			flag->offset++;
	}
	else if (str[flag->offset] == '.')
	{
		flag->precision = ft_atoui((char *)&str[flag->offset + 1]);
		while (is_num(str[flag->offset + 1]))
			flag->offset++;
	}
}

t_flags	*get_flags(const char *str)
{
	t_flags	*flag;

	flag = flag_init();
	if (!flag)
		return (NULL);
	flag->offset = 1;
	while (str[flag->offset] != 0 && !is_alpha(str[flag->offset])
		&& str[flag->offset] != '%')
	{
		if (str[flag->offset] == '#')
			flag->hex_prefix = true;
		else if (str[flag->offset] == ' ' && flag->sign == Default)
			flag->sign = Space;
		else if (str[flag->offset] == '+')
			flag->sign = Plus;
		else if (str[flag->offset] == '-')
			flag->left_justify = true;
		else
			fucc_norminette(flag, str);
		flag->offset++;
	}
	flag->type = str[flag->offset];
	conflict_check(flag);
	return (flag);
}
