/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/17 16:31:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>

static int	do_pipe(int *p_fd, int *p_rd)
{
	if (p_rd[0] == 1)
		dup2(p_fd[0], 0);
	if (p_rd[1] == 1)
		dup2(p_fd[1], 1);
	close(p_fd[0]);
	close(p_fd[1]);
	return (0);
}

static int	pathfinder(char **av, char *const envp[])
{
	int		i;

	i = -1;
	if (ft_strncmp(av[0], "exit", 5) == 0)
		exit(10);
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

static int	child(t_cmd *ptr, int *p_fd, int *p_rd, t_built *built)
{
	int			(*f)();

	do_pipe(p_fd, p_rd);
	msh_dup_fd(ptr);
	if (get_builtin(ptr->av[0], built, &f, ptr) == 1)
		exit((*f)(ft_array_len(ptr->av), ptr->av));
	else
	{
		if (pathfinder(ptr->av, envp, path) == -1)
			exit(126);
	}
	exit(0);
}

int			msh_execve(t_cmd *ptr, int *p_fd, int *p_rd, t_built *built)
{
	int			status; // to check and maybe add to stuct
	pid_t		pid;
	char		**envp;
	char		*path;

	if ((envp = lst_to_envp(g_list)) == NULL)
		return (-1);
	if ((pid = fork()) == -1)
		return (-1);
	else if (pid == 0)
		child(ptr, p_fd, p_rd, built);
	else
	{
		wait(&status);
		free(path);
		ft_array_free(envp);
	}
	return (edit_qmrk(status / 256, ptr->av[0]));
}
