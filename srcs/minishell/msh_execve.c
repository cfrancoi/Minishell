/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/27 16:11:36 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	pathfinder(char **av, char *const envp[], char *path)
{
	int		i;

	i = -1;
	while (av[0][++i])
	{
		if (av[0][i] == '/')
			return(execve(av[0], av, envp));
	}
	msh_get_path(av[0], &path);
	if (path)
		return(execve(path, av, envp));
	exit(127);
}


static int			is_builtins(int status, t_cmd *cmd)
{
	int tmp;

	tmp = status / 256;
	if (tmp == 11)
		return (msh_cd(ft_array_len(cmd->av), cmd->av));
	else if (tmp == 12)
		return (status);
	else if (tmp == 13)
		return (add_to_lst(ft_array_len(cmd->av), cmd->av));
	else if (tmp == 14)
		return (unset_parent(ft_array_len(cmd->av), cmd->av));
	return (status);
}

int	child(t_cmd *ptr, char *path, char **envp)
{
	int			(*f)();

	if (get_builtin(ptr->av[0], &f) == 1)
		exit((*f)(ft_array_len(ptr->av), ptr->av));
	else
	{
		if (pathfinder(ptr->av, envp, path) == -1)
			exit(126);
	}
	exit(0);
}

static int		wait_all(t_tfrk *lst)
{
	int status;

	status = 0;
	while (lst != NULL)
	{
		waitpid(lst->pid, &status, 0);
		status = is_builtins(status, lst->cmd); /* a fair */
		edit_qmrk(status / 256, lst->cmd->av[0]); /* a faire */
		lst = lst->next;
	}
	return (1);
}

static int		start_pipe(t_tfrk *lst)
{
	if ((pipe(lst->pfd) == -1))
		return (-1);
	else
		return (0);
}

int		start_fork(t_tfrk *lst)
{
	t_tfrk	*first;
	char	*path;
	char 	**envp;
	
	path = NULL;
	first = lst;
	if ((envp = lst_to_envp(g_all.var)) == NULL)
		return (-1);
	while (lst != NULL)
	{
		if (lst->next != NULL)
			if (start_pipe(lst) == -1)
				return (-1); /* kill all fork if failed */
		if ((lst->pid = fork()) == -1)
		{
			return (-1); /* kill all fork if failed */
		}
		else if (lst->pid == 0)
		{
			red_pipe(lst);
			msh_dup_fd(lst->cmd);
			child(lst->cmd, path, envp); // add envp is need  
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
	ft_array_free(envp);
	return(wait_all(first));
}
