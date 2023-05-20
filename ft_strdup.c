/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:12:29 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/20 18:50:58 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	size_t	index;

	index = 0;
	while (*src != '\0')
	{
		*dest++ = *src++;
		index++;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char			*temp;
	size_t			len;

	len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	ft_strcpy(temp, (char *)s1);
	return (temp);
}
