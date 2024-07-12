/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:40:49 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/12 18:25:15 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

size_t	fpf_dprintf_char(int fd, char c, t_placeholder ph)
{
	size_t	l;

	l = 0;
	if (!(ph.flags & HYPHEN) && ph.width != -1)
		l += fpf_putchar_n(ph.padding, ph.width - 1, fd);
	l += fpf_dprintf_putchar(c, fd);
	if ((ph.flags & HYPHEN) && ph.width != -1)
		l += fpf_putchar_n(ph.padding, ph.width - 1, fd);
	return (l);
}
