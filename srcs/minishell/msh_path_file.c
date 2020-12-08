/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_path_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:42:08 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 01:36:47 by user42           ###   ########.fr       */
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
	}
	return (0);
}
