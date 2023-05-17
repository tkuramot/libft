/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 23:29:35 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/18 00:16:34 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    void *b;

    if(count != 0 && size != 0 && SIZE_MAX / count / size <= 0)
        return NULL;
    b = malloc(count * size);
    if(b == NULL)
        return b;
    ft_bzero(b, count * size);
    return b;
}