/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:12:29 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/18 00:16:21 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char			*temp;
	unsigned int	len;

	len = ft_strlen(s1);
	temp = malloc(sizeof(char) * (len + 1));
	if (temp == NULL)
		return (NULL);
	ft_strcpy(temp, (char *)s1);
	return (temp);
}
