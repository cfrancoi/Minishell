/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_push_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:48:44 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/25 12:01:27 by cfrancoi         ###   ########lyon.fr   */
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
		if (sep == MSH_EOF)
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

static int	place_pipe(int (*p_fd)[2], int (*p_rd)[2], t_cmd *cmd)
{
	if (need_pipe(cmd))
	{
		
		if (p_rd[0][0] == 0 && p_rd[0][1] == 0)
		{
			p_rd[0][1] = 1;
			return (pipe(p_fd[0]));
		}
		else if (p_rd[1][0] == 0 && p_rd[1][1] == 0)
		{
			p_rd[1][1] = 1;
			
			return (pipe(p_fd[1]));
		}
	}
	return (0);
}

static int	cfg_pipe(int (*p_rd)[2])
{
	if (p_rd[0][1] == 1)
	{
		p_rd[0][1] = 0;
		p_rd[0][0] = 1;
	}
	else if (p_rd[1][1] == 1)
	{
		p_rd[1][1] = 0;
		p_rd[1][0] = 1;
	}
	return (0);
}

int			msh_push_cmd(t_cmd	**ptr)
{
	t_cmd	*cmd;
	int		p_fd[2][2];
	int		p_rd[2][2];
	

	bzero(&p_rd[0], sizeof(int) * 2);
	bzero(&p_rd[1], sizeof(int) * 2);
	cmd = *ptr;
	while (cmd != NULL)
	{
		place_pipe(p_fd, p_rd, cmd);
		if (msh_execve(cmd, p_fd, p_rd) == 10)
			msh_exit(cmd, 0);
		printf("EOF %i\n", EOF);
		cfg_pipe(p_rd);
		cmd = get_next_cmd(cmd);
	}
	return (0);
}
