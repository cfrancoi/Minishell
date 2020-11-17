/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_push_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:48:44 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/17 17:56:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>

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
		{
			ft_array_free(cmd->av);
			cmd->sep = 0;
			free(cmd);
			return (NULL);
		}
		else if (sep == PIPE || sep == SEMI)
			return (cmd->next);
		else if (sep == LFT || sep ==  RGT || sep == DRGT)
		{
			ptr = cmd->next;
			cmd->sep = 0;
			ft_array_free(cmd->av);
			free(cmd);
			cmd = ptr;
		}
	}
	return (NULL);
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
		if (msh_execve(cmd, p_fd, p_rd) == 10)
			msh_exit(cmd, 0);
		p_rd[0] = need_pipe(cmd);
		cmd = get_next_cmd(cmd);
	}
	dup2(0, fd_in);
	dup2(1, fd_out);
	close(p_fd[1]);
	close(p_fd[0]);

	return (0);
}
