/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:11:32 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 20:09:56 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int	pathfinder(char **av, char *const envp[])
{
	int		i;
	char	*path;

	i = -1;
	path = NULL;
	while (av[0][++i])
	{
		if (av[0][i] == '/')
			return (execve(av[0], av, envp));
	}
	msh_get_path(av[0], &path);
	if (path)
		return (execve(path, av, envp));
	ft_putstr_fd(av[0], 2);
	ft_putstr_fd(" : Command not found\n", 2);
	exit(ERR_CMD_NOT_FOUND);
}


static	int	is_exit_arg(t_cmd *cmd)
{
	int		i;

	i = 0;
	if (cmd->av[1] != NULL)
	{
		while (ft_isdigit(cmd->av[1][i]))
			i++;
		if (cmd->av[1][i] == '\0')
		{
			if (cmd->av[2] == NULL)
				return (1);
			else
			{
				ft_putstr_fd("msh: exit: ", 2);
				ft_putstr_fd(cmd->av[1], 2);
				ft_putendl_fd(" : too many arguments", 2);
				return (0);
			}				
		}
	}
	return (1);
}

int	start_builtins(int status, t_cmd *cmd, t_tfrk *lst)
{
	if (lst->prev == NULL && lst->next == NULL)
	{
		if (ft_strncmp(cmd->av[0], "cd", 3) == 0)
			return (msh_cd(ft_array_len(cmd->av), cmd->av));
		else if (ft_strncmp(cmd->av[0], "export", 7) == 0)
			return (add_to_lst(ft_array_len(cmd->av), cmd->av));
		else if (ft_strncmp(cmd->av[0], "unset", 6) == 0)
			return (unset_parent(ft_array_len(cmd->av), cmd->av));
		else if (ft_strncmp(cmd->av[0], "exit", 5) == 0)
		{
			if (is_exit_arg(cmd))
				g_all.step = MSH_EXIT;
			else
				return (256);
		}
	}
	return (status);
}
