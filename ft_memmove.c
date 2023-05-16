/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:01:45 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/16 19:06:31 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *d;
    const unsigned char *s; 

    d = (unsigned char *)dst;
    s  = (unsigned char *)src;
    if(dst <= src)
    {
        ft_memcpy(dst, src, len);
    }
    else
    {
        d += len;
        s += len;
        while(len)
        {
            *--d = *--s;
            len--;
        }
    }
    return dst;
}