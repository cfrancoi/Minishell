/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/11 17:54:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

static int	pathfinder(char **av)
{
	char	*path;

	if (msh_get_path(av[0], &path) != 0)
	{
		path = av[0];
	}
	else
		return (execve(path, av, NULL));
	exit(-1);
}

int			msh_execve(t_cmd *ptr, int *p_fd, int *p_rd, t_built *built)
{
	pid_t	pid;
	int		status; // to check and maybe add to stuct
	int		(*f)();

	if ((pid = fork()) == -1)
	{
		/* fail */
		return (-1);
	}
	else if (pid == 0)
	{
		/* fils */
		do_pipe(p_fd, p_rd);
		msh_dup_fd(ptr);
		if (get_builtin(ptr->av[0], built, &f, ptr) == 1)
			exit((*f)(ft_array_len(ptr->av), ptr->av));
		else
		{
			if (pathfinder(ptr->av) == -1);
				exit(-1);
		}
	}
	else
	{
		/* pere */
		wait(&status);
		if (status == 8 * 256)
			exit (0);
		printf("status : %i \n", status);
	}
	return (0);
}
