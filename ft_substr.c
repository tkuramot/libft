/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:54:05 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/19 19:50:51 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ret;
	char	*tmp;

	s_len = ft_strlen(s);
	if (s_len < start)
		len = 0;
	if (len > s_len)
		len = s_len;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	tmp = ret;
	s += start;
	while (len > 0)
	{
		*tmp++ = *s++;
		len--;
	}
	*tmp = '\0';
	return (ret);
}
