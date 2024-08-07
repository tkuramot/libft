/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:12:21 by tkuramot          #+#    #+#             */
/*   Updated: 2024/07/12 18:18:25 by kura             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*gnl_read_new_line(int fd, char *line, char **rest);
static int	gnl_concat_line(char **line, char *buffer, char **rest);

char	*get_next_line(int fd)
{
	int			flag;
	static char	*rest[FOPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	line = (char *)malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	*line = '\0';
	flag = 0;
	if (rest[fd])
		flag = gnl_concat_line(&line, rest[fd], &rest[fd]);
	if (flag)
		return (line);
	return (gnl_read_new_line(fd, line, rest));
}

static char	*gnl_read_new_line(int fd, char *line, char **rest)
{
	int		flag;
	ssize_t	n;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	flag = 0;
	while (!flag)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buffer[n] = '\0';
		flag = gnl_concat_line(&line, buffer, &rest[fd]);
	}
	if ((!gnl_strlen_s(line) && !n) || n < 0)
	{
		free(line);
		line = NULL;
	}
	free(buffer);
	return (line);
}

static int	gnl_concat_line(char **line, char *buffer, char **rest)
{
	int		flag;
	char	*tmp;
	size_t	n;

	flag = 0;
	n = gnl_find_chr(buffer, '\n');
	tmp = gnl_strnjoin(*line, buffer, gnl_strlen_s(*line), n + 1);
	if (!tmp)
		return (1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	if (buffer[n] == '\n')
	{
		flag = 1;
		tmp = gnl_strdup(buffer + n + 1);
		if (!tmp)
			return (1);
	}
	free(*rest);
	*rest = tmp;
	return (flag);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	int		n;
// 	char	*s;

// 	fd = open("sample0.txt", O_RDONLY);
// 	n = 20;
// 	for (int i = 0; i < n; i++)
// 	{
// 		printf("============%d\n", i);
// 		s = get_next_line(2);
// 		printf("%s", s);
// 		free(s);
// 	}
// }

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }
