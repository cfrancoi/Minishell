/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/05 16:14:30 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		msh_execve(char **av, t_cmd **ptr)
{
	pid_t	pid;
	int		status; // to check and maybe add to stuct

	ptr = ptr;
	if ((pid = fork()) == -1)
	{
		/* fail */
		return (-1);
	}
	else if (pid == 0)
	{
		/* fils */
		execve(av[0], av, NULL);
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
