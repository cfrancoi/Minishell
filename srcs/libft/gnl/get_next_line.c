/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:00:55 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/10/15 13:46:06 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <string.h>

int		get_next_line(int fd, char **line)
{
	static t_gnl	*mysta = NULL;
	int				n;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	n = -1;
	(mysta == NULL) ? mysta = nw(fd) : 0;
	(mysta != NULL) ? n = readline(mysta, fd, line) : 0;
	(n > 0) ? n = 1 : 0;
	if (mysta != NULL && (n == 0 || n == -1))
	{
		if (mysta->buf != NULL)
		{
			(mysta->buf != NULL) ? free(mysta->buf) : 0;
			mysta->buf = NULL;
		}
		free(mysta);
		mysta = NULL;
	}
	return (n);
}

int		readline(t_gnl *ptr, int fd, char **line)
{
	int		eol;
	char	*buf;

	eol = ft_istrchr(ptr->buf, '\n');
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	buf[BUFFER_SIZE] = '\0';
	while (eol == -1 && (((ptr->n = read(fd, buf, BUFFER_SIZE)) > 0)))
	{
		buf[ptr->n] = '\0';
		if (!(ptr->buf = ft_strjoinfree(ptr->buf, buf, 1)))
			return (-1);
		eol = ft_istrchr(ptr->buf, '\n');
	}
	if (!(*line = ft_strccpy(ptr->buf, '\n')))
		ptr->n = -1;
	free(buf);
	if (ptr->n > 0 && eol != -1)
	{
		buf = ft_strccpy(&ptr->buf[eol], '\0');
		free(ptr->buf);
		ptr->buf = buf;
	}
	return (ptr->n);
}

t_gnl	*nw(int fd)
{
	t_gnl	*ptr;

	if ((ptr = malloc(sizeof(t_gnl))) != NULL)
	{
		ptr->fd = fd;
		ptr->buf = NULL;
		ptr->n = 1;
	}
	return (ptr);
}
