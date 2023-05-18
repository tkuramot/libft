/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:51:45 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/18 22:03:27 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int idx;
    size_t s_len;
    char *ret;
    char *tmp;

    idx = 0;
    s_len = ft_strlen(s);
    ret = (char *)malloc(sizeof (char) * (s_len + 1));
    if(ret == NULL)
        return NULL;
    tmp = ret;
    while(idx < s_len)
        *tmp++ = f(idx++, *s++);
    return ret;
}