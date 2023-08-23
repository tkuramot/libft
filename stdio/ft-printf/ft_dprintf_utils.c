/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:38:43 by tkuramot          #+#    #+#             */
/*   Updated: 2023/08/23 18:38:52 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

size_t	ft_putchar_n(char c, size_t n, int fd)
{
	size_t	l;

	l = 0;
	while (n-- > 0)
		l += ft_dprintf_putchar(c, fd);
	return (l);
}

int	get_digit_count(unsigned long long nbr, size_t base)
{
	int	l;

	l = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		l++;
	}
	return (l);
}

static void	ft_putnbr_base_helper(int fd,
		unsigned long long nbr, char *base, size_t b)
{
	if (nbr >= (unsigned long long)b)
		ft_putnbr_base_helper(fd, nbr / b, base, b);
	ft_dprintf_putchar(base[nbr % b], fd);
}

size_t	ft_putnbr_base(int fd, unsigned long long nbr, char *base)
{
	size_t	b;
	size_t	l;

	b = ft_strlen(base);
	l = get_digit_count(nbr, b);
	ft_putnbr_base_helper(fd, nbr, base, b);
	return (l);
}
