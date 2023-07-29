/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:37:00 by tkuramot          #+#    #+#             */
/*   Updated: 2023/07/29 09:45:52 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

size_t	ft_printf_uint(unsigned long long nbr, t_placeholder ph)
{
	size_t		l;
	long long	digit;

	l = 0;
	digit = get_digit_count(nbr, 10);
	get_output_length(digit, &ph);
	adjust_padding(nbr, &ph);
	if (!(ph.flags & HYPHEN) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len);
	if (digit < ph.precision)
		l += ft_putchar_n('0', ph.precision - digit);
	if (!nbr && !ph.precision && ph.width != -1)
		l += ft_putchar_r(' ');
	else if (!nbr && !ph.precision)
		l += 0;
	else
		l += ft_putnbr_base(nbr, DECIMAL);
	if ((ph.flags & HYPHEN) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len);
	return (l);
}
