/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:11:32 by user42            #+#    #+#             */
/*   Updated: 2020/12/15 16:24:37 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

int			get_builtin(t_cmd *ptr, int (**f)(), char **envp)
{
	t_built	*built;

	built = g_all.built;
	if (ft_strncmp(ptr->av[0], "exit", 5) == 0)
	{
		ft_array_free((char **)envp);
		msh_free(ptr, 1);
		exit(0);
	}
	while (built)
	{
		if (ft_strncmp(ptr->av[0], built->name, ft_strlen(built->name)) == 0)
		{
			*f = built->f;
			return (1);
		}
		built = built->next;
	}
	*f = NULL;
	return (0);
}

static int	path_not_found(char **av, char *const envp[])
{
	if (errno != 0)
	{
		ft_putendl_fd(strerror(errno), 2);
		ft_array_free((char **)envp);
		ft_array_free(av);
		errno = 0;
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd(av[0], 2);
	ft_putendl_fd(" : Command not found", 2);
	ft_array_free((char **)envp);
	ft_array_free(av);
	exit(ERR_CMD_NOT_FOUND);
}

static int	is_dir(char *path, char *cmd, int save)
{
	DIR	*fdir;

	ft_putstr_fd("Msh : ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(" : ", 2);
	if ((fdir = opendir(path)) == NULL)
		errno = save;
	else
	{
		ft_putendl_fd("is a directory", 2);
		free(fdir);
		errno = 0;
	}
	return (0);
}

int			pathfinder(t_cmd *ptr, char *const envp[])
{
	int		i;
	char	*path;
	char	**av;

	i = -1;
	path = NULL;
	av = ptr->av;
	while (av[0][++i])
		if (av[0][i] == '/')
			path = ft_strdup(av[0]);
	if (path == NULL)
	{
		if (ft_strncmp(av[0], ".", 2) != 0 && ft_strncmp(av[0], "..", 3) != 0)
			msh_get_path(av[0], &path);
		msh_free(ptr, 0);
		if (path == NULL)
			return (path_not_found(av, envp));
	}
	else
		msh_free(ptr, 0);
	execve(path, av, envp);
	is_dir(path, av[0], errno);
	ft_array_free(av);
	(path != NULL) ? free(path) : 0;
	return (-1);
}
