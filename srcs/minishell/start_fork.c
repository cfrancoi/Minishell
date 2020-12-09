/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 00:17:13 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 14:34:42 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	start_pipe(t_tfrk *lst)
{
	if ((pipe(lst->pfd) == -1))
		return (-1);
	else
		return (0);
}

static void	pid_zero(t_tfrk *lst, char **envp)
{
	void	*tmp;

	tmp = lst->cmd;
	if (red_pipe(lst) == -1 || msh_dup_fd((t_cmd *)tmp) == -1)
	{
		msh_fork_error(((t_cmd *)tmp)->av[0], -1);
		msh_free(lst->cmd, 1);
		free_tfrk(lst);
		ft_array_free(envp);
		exit(EXIT_FAILURE);
	}
	free_tfrk(lst);
	child((t_cmd *)tmp, envp);
	exit(0);
}

static int	make_forks(t_tfrk *lst, char **envp)
{
	while (lst != NULL)
	{
		if (lst->next != NULL && start_pipe(lst) == -1)
			return (-1);
		if ((lst->pid = fork()) == -1)
			return (msh_fork_error(lst->cmd->av[0], MSH_EXIT));
		else if (lst->pid == 0)
			pid_zero(lst, envp);
		else
		{
			if (lst->prev != NULL)
				close(lst->prev->pfd[0]);
			if (lst->pfd[1] != 0)
				close(lst->pfd[1]);
			lst = lst->next;
		}
	}
	return (0);
}

int			start_fork(t_tfrk *lst)
{
	char	**envp;

	if ((envp = lst_to_envp(g_all.var)) == NULL)
		return (-1);
	if (make_forks(lst, envp) != 0)
	{
		ft_array_free(envp);
		return (-1);
	}
	ft_array_free(envp);
	return (wait_all(lst));
}
