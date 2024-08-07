/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:38:34 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/12 20:30:30 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		l;

	l = 0;
	va_start(ap, fmt);
	l = ft_vprintf(fd, fmt, &ap);
	va_end(ap);
	return (l);
}
