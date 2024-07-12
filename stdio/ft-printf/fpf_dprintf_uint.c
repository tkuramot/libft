/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:39:11 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/12 18:25:15 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

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

size_t	fpf_dprintf_uint(int fd, unsigned long long nbr, t_placeholder ph)
{
	size_t		l;
	long long	digit;

	l = 0;
	digit = fpf_get_digit_count(nbr, 10);
	get_output_length(digit, &ph);
	adjust_padding(nbr, &ph);
	if (!(ph.flags & HYPHEN) && ph.len < ph.width)
		l += fpf_putchar_n(ph.padding, ph.width - ph.len, fd);
	if (digit < ph.precision)
		l += fpf_putchar_n('0', ph.precision - digit, fd);
	if (!nbr && !ph.precision && ph.width != -1)
		l += fpf_dprintf_putchar(' ', fd);
	else if (!nbr && !ph.precision)
		l += 0;
	else
		l += fpf_putnbr_base(fd, nbr, DECIMAL);
	if ((ph.flags & HYPHEN) && ph.len < ph.width)
		l += fpf_putchar_n(ph.padding, ph.width - ph.len, fd);
	return (l);
}
