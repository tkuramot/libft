/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <kura@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:43:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/17 14:24:35 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *b;

    b = (unsigned char *)s;
    if(b == NULL)
        return NULL;
    while(n > 0)
    {
        if(*b == (unsigned char)c)
            return b;
        b++;
        n--;
    }
    return NULL;
}