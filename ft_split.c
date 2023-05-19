/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:33:19 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/19 16:41:39 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static size_t	get_substr_count(char const *s, char c)
{
	int		is_word;
	size_t	cnt;

	is_word = (*s == c);
	cnt = 0;
	while (*s != '\0')
	{
		if (is_word && *s == c)
			is_word = 0;
		else if (!is_word && *s != c)
		{
			cnt++;
			is_word = 1;
		}
		s++;
	}
	return (cnt);
}

static size_t	get_substr_length(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char	*extract_substr(char const *s, char c)
{
	char	*ret;
	char	*tmp;

	ret = (char *)malloc(sizeof(char) * (get_substr_length(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	tmp = ret;
	while (*s != '\0' && *s != c)
		*tmp++ = *s++;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	**tmp;

	ret = (char **)malloc(sizeof(char *) * (get_substr_count(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	tmp = ret;
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		*tmp++ = extract_substr(s, c);
		while (*s != '\0' && *s != c)
			s++;
		while (*s != '\0' && *s == c)
			s++;
	}
	*tmp = NULL;
	return (ret);
}
