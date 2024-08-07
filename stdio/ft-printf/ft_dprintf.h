/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:37:07 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/12 20:42:41 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# define HEXADECIMAL_U "0123456789ABCDEF"
# define HEXADECIMAL_L "0123456789abcdef"
# define DECIMAL "0123456789"
# define FLAGS "-0# +"

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>

typedef enum e_flag
{
	HYPHEN = 1 << 0,
	ZERO = 1 << 1,
	HASH = 1 << 2,
	SPACE = 1 << 3,
	PLUS = 1 << 4
}				t_flag;

typedef enum e_type
{
	CHAR,
	STR,
	PTR,
	DEC,
	INT,
	U_DEC,
	HEX_U,
	HEX_L,
	PERCENT
}				t_type;

typedef struct s_placeholder
{
	long long	flags;
	long long	width;
	long long	precision;
	t_type		type;
	char		padding;
	long long	len;
}				t_placeholder;

int				ft_printf(const char *fmt, ...);
int				ft_dprintf(int fd, const char *fmt, ...);
int				ft_vprintf(int fd, const char *fmt, va_list *ap);
size_t			fpf_putnbr_base(int fd, unsigned long long nbr, char *base);
int				fpf_get_digit_count(unsigned long long nbr, size_t base);
size_t			fpf_dprintf_ptr(int fd, unsigned long long p, t_placeholder ph);
size_t			fpf_dprintf_int(int fd, long long nbr, t_placeholder ph);
size_t			fpf_dprintf_lower_hex(int fd, unsigned long long nbr,
					t_placeholder ph);
size_t			fpf_dprintf_upper_hex(int fd, unsigned long long nbr,
					t_placeholder ph);
size_t			fpf_dprintf_uint(int fd, unsigned long long nbr,
					t_placeholder ph);
size_t			fpf_dprintf_percent(int fd, t_placeholder ph);
size_t			fpf_dprintf_char(int fd, char c, t_placeholder ph);
size_t			fpf_dprintf_str(int fd, char *s, t_placeholder ph);
size_t			fpf_dprintf_putchar(char c, int fd);
size_t			fpf_putchar_n(char c, size_t n, int fd);
size_t			fpf_dprintf_putstr(char *s, int fd);
size_t			fpf_dprintf_putnstr(char *s, size_t n, int fd);

#endif
