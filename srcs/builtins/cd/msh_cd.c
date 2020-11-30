/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:26:35 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/30 16:47:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"
#include <dirent.h>
#include <stdio.h>
#include <sys/errno.h>

static int			is_abs_path(char *ptr)
{
	if (ptr[0] == '\\')
		return (1);
	return (0);
}

static int			is_relativ_path(char *ptr)
{
	char		*cwd;
	DIR			*fdir;

	if ((cwd = getcwd(NULL, 0)) == NULL)
		return (-1);
	if ((cwd = ft_strjoinf(cwd, "/", 1)) == NULL)
		return (-1);
	if ((cwd = ft_strjoinf(cwd, ptr, 1)) == NULL)
		return (-1);
	if ((fdir = opendir(cwd)) == NULL)
		return (-1);
	free(fdir);
	return (1);
}


int			msh_cd(int ac, char **argv)
{
	char		*path;

	(void)argv;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (is_abs_path(argv[1]))
		{
			if (chdir(argv[1]) == -1)
				return (-1);
			else
				return (0);
		}
		if (is_relativ_path(argv[1]) == -1)
		{
			printf("msh cd : %s\n", strerror(errno));
		}
		else
		{
			path = ft_strjoinf(getcwd(NULL, 0), "/", 1);
			path = ft_strjoinf(path, argv[1], 1);
			chdir(path);
			return (0);
		}
	}
	return (0);
}
