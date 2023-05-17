/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kura <kura@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:20:46 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/17 13:55:40 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char *ft_strchr(const char *s, int c)
{
    char *ret;

    ret = NULL;
    while(*s != '\0' && *s != (char)c)
        s++;
    if(*s == (char)c)
        ret = (char *)s;
    return ret;
}