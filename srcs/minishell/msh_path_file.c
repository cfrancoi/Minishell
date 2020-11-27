/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_path_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:42:08 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/27 15:42:37 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <errno.h>
#include <stdio.h>

int		msh_path_file(char *path)
{
	int fd;

	if ((fd = open(path, O_RDONLY) == -1))
	{
		printf("%s : %s\n", path, strerror(errno));
	}
	return (0);
}
