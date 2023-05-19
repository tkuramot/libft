/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:20:46 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/19 16:41:49 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		ret = (char *)s;
	return (ret);
}
