/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 00:56:50 by tkuramot          #+#    #+#             */
/*   Updated: 2023/09/20 01:00:46 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdlib.h"

char	*ft_chrdup(const char c)
{
	char	*c_ptr;

	c_ptr = ft_calloc(1, sizeof (char));
	if (!c_ptr)
		return (NULL);
	*c_ptr = c;
	return (c_ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%c\n", *ft_chrdup('A'));
	return (0);
}
*/
