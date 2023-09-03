/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:40:49 by tkuramot          #+#    #+#             */
/*   Updated: 2023/08/23 18:40:50 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

size_t	ft_dprintf_char(int fd, char c, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (!(ph.flags & HYPHEN) && ph.width != -1)
		l += ft_putchar_n(ph.padding, ph.width - 1, fd);
	l += ft_dprintf_putchar(c, fd);
	if ((ph.flags & HYPHEN) && ph.width != -1)
		l += ft_putchar_n(ph.padding, ph.width - 1, fd);
	return (l);
}
