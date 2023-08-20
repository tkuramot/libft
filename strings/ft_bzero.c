/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:25:45 by tkuramot          #+#    #+#             */
/*   Updated: 2023/08/20 16:53:19 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <string.h>

// int	main(void)
// {
// 	// ft_bzero(NULL, 0);
// 	ft_bzero(NULL, 1);
// 	// bzero(NULL, 0);
// 	bzero(NULL, 1);
// }
