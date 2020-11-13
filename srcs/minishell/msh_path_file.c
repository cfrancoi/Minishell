/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_path_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:42:08 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/13 16:55:56 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <errno.h>
#include <stdio.h>

int		msh_path_file(char *path)
{
	int fd;
		if ((fd = open(path, O_RDONLY) == -1 ))
		{
			printf("%s : %s\n", path, strerror(errno));
		}
		return (0);
}

int		main(int ac, char	**av)
{
	if (ac == 2)
		msh_path_file(av[1]);
		return (0);
	
}

