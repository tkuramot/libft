/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <kura@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:38:19 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/17 14:06:48 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    char *found;
    char *p;

    if(c == '\0')
        return ft_strchr(s, '\0');
    found = NULL;
    p = ft_strchr(s, c);
    while(p != NULL)
    {
        found = p;
        s = p + 1;
        p = ft_strchr(s, c);
    }
    return found;
}