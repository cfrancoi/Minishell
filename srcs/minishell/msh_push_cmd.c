/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_push_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:48:44 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/09 18:10:32 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_cmd	*get_next_cmd(t_cmd *ptr)
{
	t_cmd	*cmd;
	int		sep;

	sep = 0;
	cmd = ptr;
	while (cmd != NULL)
	{
		sep = cmd->sep;
		if (sep == EOF)
			return (NULL);
		else if (sep == PIPE || sep == SEMI)
			return (cmd->next);
		else if (sep == LFT || sep ==  RGT || sep == DRGT)
			cmd = cmd->next;
	}
}

static int		need_pipe(t_cmd *cmd)
{
	int sep;

	sep = 0;
	while (cmd != NULL)
	{
		sep = cmd->sep;
		if (sep == LFT || sep ==  RGT || sep == DRGT)
			cmd = cmd->next;
		else if (sep == PIPE)
			return (1);
		else if (sep == SEMI || sep == EOF)
			return (0);
	}
	return (0);
}

int			msh_push_cmd(t_cmd	**ptr)
{
	t_cmd	*cmd;
	int		p_fd[2];
	int		p_rd[2];
	

	p_rd[0] = 0;
	p_rd[1] = 0;
	
	int fd_out = dup(1);
	int fd_in = dup(0);
	cmd = *ptr;
	pipe(p_fd);
	while (cmd != NULL)
	{
		p_rd[1] = need_pipe(cmd);
		msh_execve(cmd, p_fd, p_rd);
		
		p_rd[0] = need_pipe(cmd);
		cmd = get_next_cmd(cmd);


	}
	dup2(0, fd_in);
	dup2(1, fd_out);
	close(p_fd[1]);
	close(p_fd[0]);

	return (0);
}

/*
   -1 : n/a						/ start
	0 : fd[1] -> 1				/ pipe first execve
	1 : fd[0] -> 0				/ next if no futur pipe
	2 : fd[1] -> 1 fd[0] -> 0

*/
