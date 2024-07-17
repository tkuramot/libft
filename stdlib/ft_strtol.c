/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:13 by kura              #+#    #+#             */
/*   Updated: 2024/07/17 22:05:15 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

static int	check_sign(char *str, int *i)
{
	int	sign;

	sign = 1;
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '-')
	{
		sign *= -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

static bool	check_overflow(long current, int base, int next)
{
	long	div;
	long	mod;

	div = LONG_MAX / base;
	mod = LONG_MAX % base;
	if (current > div || (current == div && next > mod))
	{
		errno = ERANGE;
		return (true);
	}
	div = LONG_MIN / base;
	mod = -(LONG_MIN % base);
	if (current < div || (current == div && next > mod))
	{
		errno = ERANGE;
		return (true);
	}
	return (false);
}

long	ft_strtol(char *str, char *endptr, int base)
{
	int		sign;
	long	nb;
	int		i;

	sign = 1;
	nb = 0;
	i = 0;
	sign = check_sign(str, &i);
	while (ft_isdigit(str[i]))
	{
		if (check_overflow(nb * sign, base, str[i] - '0'))
		{
			if (sign == 1)
				nb = LONG_MAX;
			else
				nb = LONG_MIN;
			break ;
		}
		nb = (nb * base) + (str[i] - '0');
		i++;
	}
	if (endptr)
		*endptr = str[i];
	return (nb * sign);
}
