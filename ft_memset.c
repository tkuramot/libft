/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:06:40 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/16 18:00:03 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void *ft_memset(void *b, int c, size_t len)
{
    unsigned char *s;

    s = (unsigned char *)b;
    while(len != 0)
    {
        *s++ = (unsigned char)c;
        len--;
    }
    return (b);
}