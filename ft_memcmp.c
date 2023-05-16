/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:46:09 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/16 21:50:39 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char *b1;
    unsigned char *b2;

    b1 = (unsigned char *)s1;
    b2 = (unsigned char *)s2;
    while(n > 0 && *b1 != '\0' && (*b1 == *b2))
    {
        b1++;
        b2++;
        n--;
    }
    return (unsigned char)*b1 - (unsigned char)*b2;
}