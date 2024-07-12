/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_putnstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:39:37 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/12 18:25:15 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

size_t	fpf_dprintf_putnstr(char *s, size_t n, int fd)
{
	size_t	ret;

	ret = n;
	while (n--)
		fpf_dprintf_putchar(*s++, fd);
	return (ret);
}
