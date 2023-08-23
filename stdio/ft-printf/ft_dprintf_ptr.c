/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:40:02 by tkuramot          #+#    #+#             */
/*   Updated: 2023/08/23 18:40:20 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

size_t	ft_dprintf_ptr(int fd, unsigned long long ptr, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (!(ph.flags & HYPHEN) && get_digit_count(ptr, 16) + 2 < ph.width)
		l += ft_putchar_n(ph.padding,
				ph.width - get_digit_count(ptr, 16) - 2, fd);
	l += ft_dprintf_putstr("0x", fd);
	l += ft_putnbr_base(fd, ptr, HEXADECIMAL_L);
	if ((ph.flags & HYPHEN) && get_digit_count(ptr, 16) + 2 < ph.width)
		l += ft_putchar_n(ph.padding,
				ph.width - get_digit_count(ptr, 16) - 2, fd);
	return (l);
}
