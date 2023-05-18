/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:54:27 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/18 14:41:07 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *str)
{
	int	sign;
	long long	nb;

	sign = 1;
	nb = 0;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r')) str++;
	if (*str == '-')
	{
        sign *= -1;
		str++;
	}
    else if(*str == '+') str++;
	while ('0' <= *str && *str <= '9')
	{
        if(nb * sign > LONG_MAX / 10 || (nb * sign == LONG_MAX / 10 && *str - '0' > LONG_MAX % 10))
            return (int)(LONG_MAX);
        if(nb * sign < LONG_MIN / 10 || (nb * sign == LONG_MIN / 10 && *str - '0' > -(LONG_MIN % 10)))
            return (int)(LONG_MIN);
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (int)(nb * sign);
}