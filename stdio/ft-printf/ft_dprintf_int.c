/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:40:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/08/23 18:40:44 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static bool	ft_abs(long long *nbr)
{
	bool	is_neg;

	is_neg = *nbr < 0;
	if (is_neg)
		*nbr *= -1;
	return (is_neg);
}

static size_t	print_sign(int fd, bool is_neg, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (is_neg)
	{
		l += ft_dprintf_putchar('-', fd);
	}
	else
	{
		if (ph.flags & PLUS)
			l += ft_dprintf_putchar('+', fd);
		else if (ph.flags & SPACE)
			l += ft_dprintf_putchar(' ', fd);
	}
	return (l);
}

static void	get_output_length(long long digit, t_placeholder *ph)
{
	if (ph->precision != -1 && ph->precision > digit)
		ph->len = ph->precision;
	else
		ph->len = digit;
}

static void	adjust_padding(long long nbr, t_placeholder *ph)
{
	if (!nbr && !ph->precision && (ph->flags & ZERO))
		ph->padding = ' ';
	if (ph->precision != -1 && (ph->flags & ZERO))
	{
		ph->padding = ' ';
		ph->flags ^= ZERO;
	}
}

size_t	ft_dprintf_int(int fd, long long nbr, t_placeholder ph)
{
	size_t		l;
	long long	digit;
	bool		is_neg;

	l = 0;
	is_neg = ft_abs(&nbr);
	digit = get_digit_count(nbr, 10);
	get_output_length(digit, &ph);
	adjust_padding(nbr, &ph);
	if (!(ph.flags & HYPHEN) && !(ph.flags & ZERO) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len - is_neg, fd);
	l += print_sign(fd, is_neg, ph);
	if (!(ph.flags & HYPHEN) && (ph.flags & ZERO) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len - is_neg, fd);
	if (digit < ph.precision)
		l += ft_putchar_n('0', ph.precision - digit, fd);
	if (!nbr && !ph.precision && ph.width != -1)
		l += ft_dprintf_putchar(' ', fd);
	else if (!nbr && !ph.precision)
		l += 0;
	else
		l += ft_putnbr_base(fd, nbr, DECIMAL);
	if ((ph.flags & HYPHEN) && !(ph.flags & ZERO) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len - is_neg, fd);
	return (l);
}
