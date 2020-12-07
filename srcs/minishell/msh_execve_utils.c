/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:11:32 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 15:42:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	exit(127);
}

int	is_builtins(int status, t_cmd *cmd, t_tfrk *lst)
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
			g_all.step = MSH_EXIT;
		}
	}
	return (status);
}
