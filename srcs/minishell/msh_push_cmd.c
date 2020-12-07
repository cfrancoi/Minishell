/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_push_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:48:44 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/07 20:12:30 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cmd	*end_of_line(t_cmd *cmd)
{
	ft_array_free(cmd->av);
	cmd->sep = 0;
	free(cmd);
	return (NULL);
}

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
			return (end_of_line(cmd));
		else if (sep == SEMI)
			return (cmd->next);
		else if (sep == LFT || sep == RGT || sep == DRGT || sep == PIPE)
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

int				msh_push_cmd(t_cmd **ptr)
{
	t_cmd	*cmd;
	t_tfrk	*lst;

	cmd = *ptr;
	while (cmd != NULL)
	{
		if ((lst = crt_lst(cmd)) == NULL)
			return (MSH_EXIT);
		if ((start_fork(lst)) == MSH_EXIT)
		{
			free_tfrk(lst);
			*ptr = cmd;
			return (MSH_EXIT);
		}
		free_tfrk(lst);
		cmd = get_next_cmd(cmd);
	}
	*ptr = NULL;
	return (0);
}
