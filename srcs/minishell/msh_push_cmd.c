/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_push_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:48:44 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/30 15:52:31 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		else if (sep == SEMI)
			return (cmd->next);
		else if (sep == LFT || sep ==  RGT || sep == DRGT || sep == PIPE)
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
	t_tfrk	*lst;

	cmd = *ptr;
	while (cmd != NULL)
	{
		lst = crt_lst(cmd); /* lst of cmd to fork */
		/*	*/
		start_fork(lst);
		free_tfrk(lst);
		/* free lst */
		cmd = get_next_cmd(cmd);
	}
	return (0);
}
