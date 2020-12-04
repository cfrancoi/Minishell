/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/04 16:26:26 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			child(t_cmd *ptr, char **envp)
{
	int			(*f)();

	if (get_builtin(ptr->av[0], &f) == 1)
		exit((*f)(ft_array_len(ptr->av), ptr->av));
	else
	{
		if (pathfinder(ptr->av, envp) == -1)
			exit(126);
	}
	exit(0);
}

static int	wait_all(t_tfrk *lst)
{
	int status;

	status = 0;
	while (lst != NULL)
	{
		waitpid(lst->pid, &status, 0);
		
		if (!(lst->prev) && !(lst->next))
			status = is_builtins(status, lst->cmd, lst); /* a fair */
//		if (!(g_all.step == MSH_EXIT && lst->prev == NULL && lst->next == NULL))
//			g_all.step = MSH_STCMD;
		edit_qmrk(status / 256, lst->cmd->av[0]); /* a faire */
		lst = lst->next;
	}
	if (WIFSIGNALED(status))
	{
#ifdef WCOREDUMP
		if (WCOREDUMP(status))
			ft_putstr_fd("Core dumped\n", 2);
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
	while (lst != NULL)
	{
		if (lst->next != NULL && start_pipe(lst) == -1)
			return (-1); /* kill all fork if failed */
		if ((lst->pid = fork()) == -1)
			return (-1); /* kill all fork if failed */
		else if (lst->pid == 0)
		{
			red_pipe(lst);
			msh_dup_fd(lst->cmd);
			child(lst->cmd, envp); // add envp is need  
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
	char 	**envp;
	
	if ((envp = lst_to_envp(g_all.var)) == NULL)
		return (-1);
	if (make_forks(lst, envp) != 0)
		return (-1);
	ft_array_free(envp);
	return(wait_all(lst));
}
