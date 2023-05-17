/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <kura@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:27:52 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/17 09:32:20 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;

	index = 0;
	while (index + 1 < dstsize && *src != '\0')
	{
		*dst++ = *src++;
		index++;
	}
	*dst = '\0';
	while (*src++ != '\0')
		index++;
	return (index);
}