/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 02:05:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			child(t_cmd *ptr, char **envp)
{
	int		(*f)();
	int		ret;

	ret = 0;
	if (get_builtin(ptr, &f, envp) == 1)
	{
		ret = (*f)(ft_array_len(ptr->av), ptr->av);
		ft_array_free(envp);
		msh_free(ptr, 1);
		exit(ret);
	}
	else
	{
		if (pathfinder(ptr, envp) == -1)
		{
			ft_putendl_fd(strerror(errno), 2);
			ft_array_free(envp);
			exit(ERR_EXECVE);
		}
	}
	exit(ret);
}

static int	kill_all(t_tfrk *lst)
{
	msh_fork_error("wait", -1);
	while (lst)
	{
		kill(lst->pid, SIGKILL);
		lst = lst->next;
	}
	if (errno != 0)
		errno = 0;
	return (-1);
}

int			wait_all(t_tfrk *lst)
{
	int status;

	status = 0;
	while (lst != NULL)
	{
		if ((waitpid(lst->pid, &status, 0)) == -1)
			return (kill_all(lst->next));
		if (!(lst->prev) && !(lst->next))
			status = start_builtins(status, lst->cmd, lst);
		if (g_all.step != MSH_SIGINT && g_all.step != MSH_SIGQUIT)
			edit_qmrk(status / 256);
		lst = lst->next;
	}
	if (WIFSIGNALED(status))
	{
		if (WCOREDUMP(status))
			ft_putendl_fd("Core dumped", 2);
	}
	return (g_all.step);
}
