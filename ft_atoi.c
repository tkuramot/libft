/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:54:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/18 01:58:53 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *str)
{
	int	sign;
	long long	nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (int)(nb * sign);
}