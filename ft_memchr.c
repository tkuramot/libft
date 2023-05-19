/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:43:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/19 16:49:13 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*b;

	b = (unsigned char *)s;
	if (b == NULL)
		return (NULL);
	while (n > 0)
	{
		if (*b == (unsigned char)c)
			return (b);
		b++;
		n--;
	}
	return (NULL);
}
