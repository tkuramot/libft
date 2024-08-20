/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:13 by kura              #+#    #+#             */
/*   Updated: 2024/08/20 23:58:35 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

static long	check_sign(char **str)
{
	long	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	determine_base(char **str, int base)
{
	if (base == 0)
	{
		if (**str == '0')
		{
			if (*(*str + 1) == 'x' || *(*str + 1) == 'X')
			{
				base = 16;
				*str += 2;
			}
			else
			{
				base = 8;
				(*str)++;
			}
		}
		else
			base = 10;
	}
	else if (base == 16 && **str == '0' && (*(*str + 1) == 'x' || *(*str
				+ 1) == 'X'))
	{
		*str += 2;
	}
	return (base);
}

static long	char_to_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (-1);
}

static long	add_digit_to_result(long result, long digit, int base, long sign)
{
	if (result > (LONG_MAX - digit) / base)
	{
		errno = ERANGE;
		if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	return (result * base + digit);
}

long	ft_strtol(char *str, char **endptr, int base)
{
	long	result;
	long	sign;
	long	digit;

	result = 0;
	while (ft_isspace(*str))
		str++;
	sign = check_sign(&str);
	base = determine_base(&str, base);
	while (ft_isdigit(*str) || (*str >= 'a' && *str <= 'z') || (*str >= 'A'
			&& *str <= 'Z'))
	{
		digit = char_to_digit(*str);
		if (digit < 0 || digit >= base)
			break ;
		result = add_digit_to_result(result, digit, base, sign);
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (result * sign);
}
