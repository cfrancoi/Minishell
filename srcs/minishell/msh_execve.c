/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/09 18:05:13 by cfrancoi         ###   ########lyon.fr   */
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

int			msh_execve(t_cmd *ptr, int *p_fd, int *p_rd)
{
	pid_t	pid;
	int		status; // to check and maybe add to stuct

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
		execve(ptr->av[0], ptr->av, NULL);
		/* if fail*/
		return (-1);
	}
	else
	{
		/* pere */
		wait(&status);
	}
	return (0);
}
