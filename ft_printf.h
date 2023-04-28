/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:20:00 by fedmarti          #+#    #+#             */
/*   Updated: 2023/04/02 18:02:17 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>

enum	e_sign_flag{
	Default,
	Plus,
	Space
};

typedef struct s_flags{
	char				type;
	enum e_sign_flag	sign;
	int					width;
	int					precision;
	bool				left_justify;
	bool				hex_prefix;
	bool				zero_padding;
	int					offset;
}	t_flags;

int		ft_putstr(char *str);
int		ft_printf(const char *str, ...);
int		print_arg(va_list args, t_flags *flags);
int		ft_putchar(char c);
int		ft_put_p(void *p);
int		ft_put_u(unsigned int n);
int		ft_puthex(size_t n, char flag);
int		ft_put_d(int n);
t_flags	*get_flags(const char *str);
bool	is_alpha(char c);
bool	is_num(char c);
bool	in(int goal, ...);
int		ft_atoui(char *str);
char	*ft_itoa(long n);
int		print_str(char *str, t_flags *flag);
int		print_int(int n, t_flags *flag);
int		print_unsigned(unsigned int n, t_flags *flag);
int		ft_strlen(const	char *str);
int		handle_padding(char *str, t_flags *flag);
int		print_pointer(void *p, t_flags *flag);
char	*ft_ultoa_base(long unsigned n, char *base);
char	*ft_utoa_base(unsigned int n, char *base);
char	*ft_strjoin(char *s1, char *s2);
int		print_hex(unsigned int n, t_flags *flag);
char	*handle_precision(char	*num, t_flags *flag);

#endif
