/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:39:20 by tkuramot          #+#    #+#             */
/*   Updated: 2023/08/23 18:39:21 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static void	get_output_length(char *s, t_placeholder *ph)
{
	size_t	l;

	l = ft_strlen(s);
	if (ph->precision != -1 && ph->precision < (long long)l)
		ph->len = ph->precision;
	else
		ph->len = l;
}

size_t	ft_dprintf_str(int fd, char *s, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (!s)
		return (ft_dprintf_str(fd, "(null)", ph));
	get_output_length(s, &ph);
	if (!(ph.flags & HYPHEN) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len, fd);
	if (ph.precision != -1 && ph.precision < (long long)ft_strlen(s))
		l += ft_dprintf_putnstr(s, ph.precision, fd);
	else
		l += ft_dprintf_putstr(s, fd);
	if ((ph.flags & HYPHEN) && ph.len < ph.width)
		l += ft_putchar_n(ph.padding, ph.width - ph.len, fd);
	return (l);
}
