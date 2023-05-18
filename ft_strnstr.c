/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:23:28 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/18 09:27:01 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	compare(const char *s1, const char *s2, size_t len)
{
	while (*s1 != '\0' && *s2 != '\0' && len > 0)
	{
		if (*s1 != *s2)
		{
			return (0);
		}
		s1++;
		s2++;
        len--;
	}
	return (*s2 == '\0');
}

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (len > 0 && *haystack != '\0')
	{
		if ((*haystack == *needle) && compare(haystack, needle, len))
			return ((char *)haystack);
		haystack++;
        len--;
	}
	return (NULL);
}
