/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 16:12:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int			child(t_cmd *ptr, char **envp)
{
	int		(*f)();
	int		ret;
	char	**av;

	ret = 0;
	av = ptr->av;
	if (get_builtin(ptr, &f, envp) == 1)
	{
		ret = (*f)(ft_array_len(av), av);
		ft_array_free(envp);
		msh_free(ptr, 1);
		exit(ret);
	}
	msh_free(ptr, 0);
	else
	{
		if (pathfinder(av, envp) == -1)
		{
			ft_putendl_fd(strerror(errno), 2);
			ft_array_free(envp);
			ft_array_free(av);
			exit(ERR_EXECVE);
		}
	}
	exit(ret);
}

static int	wait_all(t_tfrk *lst)
{
	int status;

	status = 0;
	while (lst != NULL)
	{
		waitpid(lst->pid, &status, 0);
		if (!(lst->prev) && !(lst->next))
			status = start_builtins(status, lst->cmd, lst);
		edit_qmrk(status / 256);
		lst = lst->next;
	}
	if (WIFSIGNALED(status))
	{
#ifdef WCOREDUMP
		if (WCOREDUMP(status))
			ft_putendl_fd("Core dumped", 2);
#endif
	}
	return (g_all.step);
}

static int	start_pipe(t_tfrk *lst)
{
	if ((pipe(lst->pfd) == -1))
		return (-1);
	else
		return (0);
}

static int	make_forks(t_tfrk *lst, char **envp)
{
	void	*tmp;

	while (lst != NULL)
	{
		if (lst->next != NULL && start_pipe(lst) == -1)
			return (-1);
		if ((lst->pid = fork()) == -1)
			return (-1);
		else if (lst->pid == 0)
		{
			tmp = lst->cmd;
			red_pipe(lst);
			free_tfrk(lst);
			msh_dup_fd((t_cmd *)tmp);
			child((t_cmd *)tmp, envp);
			exit(0);
		}
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
		return (-1);
	ft_array_free(envp);
	return (wait_all(lst));
}
