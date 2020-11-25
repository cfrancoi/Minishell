/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/25 17:40:07 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	do_pipe(int (*p_fd)[2], int (*p_rd)[2])
{
	if (!(p_rd[0][0] == 0 && p_rd[0][1] == 0))
	{
		if (p_rd[0][0] == 1)
			dup2(p_fd[0][0], 0);
		if (p_rd[0][1] == 1)
			dup2(p_fd[0][1], 1);
		close(p_fd[0][0]);
		close(p_fd[0][1]);
	}
	if (!(p_rd[1][0] == 0 && p_rd[1][1] == 0))
	{
		if (p_rd[1][0] == 1)
			dup2(p_fd[1][0], 0);
		if (p_rd[1][1] == 1)
			dup2(p_fd[1][1], 1);
		close(p_fd[1][0]);
		close(p_fd[1][1]);
	}
	return (0);
}

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

static int	child(t_cmd *ptr, char *path, char **envp)
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

static int	close_pipe(int (*p_fd)[2], int (*p_rd)[2])
{
	if (p_rd[0][0] == 1)
	{
		p_rd[0][1] = 0;
		p_rd[0][0] = 0;
		close(p_fd[0][0]);
		close(p_fd[0][1]);
	}
	else if (p_rd[1][0] == 1)
	{
		p_rd[1][1] = 0;
		p_rd[1][0] = 0;
		close(p_fd[1][0]);
		close(p_fd[1][1]);
	}
	return (0);
}

int			msh_execve(t_cmd *ptr, int (*p_fd)[2], int (*p_rd)[2])
{
	int			status;
	pid_t		pid;
	char		**envp;
	char		*path;

	status = 0;
	path = NULL;
	if ((envp = lst_to_envp(g_all.var)) == NULL)
		return (-1);
	if ((pid = fork()) == -1)
		return (-1);
	else if (pid == 0)
	{
		do_pipe(p_fd, p_rd);
		msh_dup_fd(ptr);
		child(ptr, path, envp);
		exit(0);
	}
	else
	{
		close_pipe(p_fd, p_rd);
		wait(&status);
		if (path != NULL)
			free(path);
		ft_array_free(envp);
		status = is_builtins(status, ptr);
	}
	return (edit_qmrk(status / 256, ptr->av[0]));
}
