/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 22:15:20 by cfrancoi         ###   ########lyon.fr   */
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

static int	wait_all(t_tfrk *lst)
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
# ifdef WCOREDUMP
		if (WCOREDUMP(status))
			ft_putendl_fd("Core dumped", 2);
# endif
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
			return (msh_fork_error(lst->cmd->av[0], MSH_EXIT));
		else if (lst->pid == 0)
		{
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
