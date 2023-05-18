/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:16:41 by tkuramot          #+#    #+#             */
/*   Updated: 2023/05/18 22:26:39 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr_fd(int n, int fd)
{
    char c;

    c = (n % 10) + '0';
    if(n < 10)
    {
        write(fd, &c, 1);
        return ;
    }
    ft_putnbr_fd(n / 10, fd);
    write(fd, &c, 1);
}