/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:11:32 by user42            #+#    #+#             */
/*   Updated: 2020/12/08 17:16:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_exit_arg(t_cmd *cmd)
{
	int	i;

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

static int	path_not_found(char **av,  char *const envp[])
{
	if (errno != 0)
	{
		ft_putendl_fd(strerror(errno), 2);
		ft_array_free((char **)envp);
		ft_array_free(av);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd(av[0], 2);
	ft_putendl_fd(" : Command not found", 2);
	ft_array_free((char **)envp);
	ft_array_free(av);
	exit(ERR_CMD_NOT_FOUND);
}

int			pathfinder(t_cmd *ptr, char *const envp[])
{
	int		i;
	char	*path;
	char	**av;

	i = -1;
	path = NULL;
	av = ptr->av;
	ft_putendl_fd(av[0], 1);
	while (av[0][++i])
	{
		if (av[0][i] == '/')
		{
			msh_free(ptr, 0);
			return (execve(av[0], av, envp));
		}
	}
	msh_get_path(av[0], &path);
	msh_free(ptr, 0);
	if (path)
		return (execve(path, av, envp));
	return (path_not_found(av, envp));
}

int			start_builtins(int status, t_cmd *cmd, t_tfrk *lst)
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
