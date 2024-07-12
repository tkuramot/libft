/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:40:02 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/12 18:25:15 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

size_t	fpf_dprintf_ptr(int fd, unsigned long long ptr, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (!(ph.flags & HYPHEN) && fpf_get_digit_count(ptr, 16) + 2 < ph.width)
		l += fpf_putchar_n(ph.padding,
				ph.width - fpf_get_digit_count(ptr, 16) - 2, fd);
	l += fpf_dprintf_putstr("0x", fd);
	l += fpf_putnbr_base(fd, ptr, HEXADECIMAL_L);
	if ((ph.flags & HYPHEN) && fpf_get_digit_count(ptr, 16) + 2 < ph.width)
		l += fpf_putchar_n(ph.padding,
				ph.width - fpf_get_digit_count(ptr, 16) - 2, fd);
	return (l);
}
