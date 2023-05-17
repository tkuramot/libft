/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 19:53:36 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/18 01:01:14 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t	index;
	size_t	max_copy;
	size_t	dest_str_len;
	size_t	src_str_len;

	src_str_len = ft_strlen(src);
    if(dst == NULL)
        return src_str_len;
	dest_str_len = ft_strlen(dst);
	if (dstsize <= dest_str_len)
		return (dstsize + src_str_len);
	max_copy = dstsize - dest_str_len - 1;
	index = 0;
    dst += dest_str_len;
	while (index < max_copy)
	{
		if (*src == '\0')
			break ;
		*dst++ = *src++;
		index++;
	}
	*dst = '\0';
	return (src_str_len + dest_str_len);
}