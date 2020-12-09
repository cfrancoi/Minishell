/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_path_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:42:08 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 18:59:37 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int		msh_path_file(char *path)
{
	int fd;

	if ((fd = open(path, O_RDONLY) == -1))
	{
		ft_putstr_fd(path, 1);
		ft_putstr_fd(" : ", 1);
		ft_putendl_fd(strerror(errno), 1);
		errno = 0;
	}
	return (0);
}
