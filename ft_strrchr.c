/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:38:19 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/16 21:39:22 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strrchr(const char *s, int c)
{
    char *ret;

    ret = NULL;
    while(*s++ != '\0')
    {
        if(*s == c)
            ret = s;
    }
    return ret;
}