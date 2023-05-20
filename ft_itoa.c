/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:33:59 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:46:29 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_number_of_digits(int n)
{
	size_t	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*ret;
	char	*tmp;
	size_t	len;
	int		is_negative;

	is_negative = (n < 0);
	len = get_number_of_digits(n) + is_negative;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	tmp = ret + len;
	*tmp-- = '\0';
	while (len-- > 0)
	{
		if (!is_negative)
			*tmp-- = (n % 10) + '0';
		else
			*tmp-- = -(n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		*(tmp + 1) = '-';
	return (ret);
}
