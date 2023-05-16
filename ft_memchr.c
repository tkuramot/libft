/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:43:24 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/16 21:49:48 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *b;

    b = (unsigned char *)s;
    while(n > 0)
    {
        if(*b++ == c)
            return b;
    }
    return NULL;
}