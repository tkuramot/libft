/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:44:26 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/18 16:52:48 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t s1_len;
    size_t s2_len;
    size_t dstsize;
    char *ret;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    dstsize = s1_len + s2_len + 1;
    ret = (char *)malloc(sizeof (char) * dstsize);
    if(ret == NULL)
        return NULL;
    ft_strlcpy(ret, s1, sizeof (char) * dstsize);
    ft_strlcat(ret, s2, sizeof (char) * dstsize);
    return ret;
}