/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_tfrk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:52:03 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 19:03:23 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "msh_execve.h"

t_tfrk			*nw_frk(t_tfrk *prev, t_cmd *cmd)
{
	t_tfrk	*nw;

	if ((nw = ft_calloc(sizeof(t_tfrk), 1)) == NULL)
		return (NULL);
	nw->prev = prev;
	nw->cmd = cmd;
	return (nw);
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
		if (sep == MSH_EOF || sep == SEMI)
		{
			return (NULL);
		}
		else if (sep == PIPE)
			return (cmd->next);
		else if (sep == LFT || sep == RGT || sep == DRGT)
		{
			cmd = cmd->next;
		}
	}
	return (NULL);
}

t_tfrk			*crt_lst(t_cmd *cmd)
{
	t_tfrk	*lst;
	t_tfrk	*first;

	if ((lst = nw_frk(NULL, cmd)) == NULL)
		return (NULL);
	first = lst;
	while ((cmd = get_next_cmd(cmd)))
	{
		if ((lst->next = nw_frk(lst, cmd)) == NULL)
		{
			free_tfrk(first);
			return (NULL);
		}
		lst = lst->next;
	}
	return (first);
}

void			free_tfrk(t_tfrk *lst)
{
	t_tfrk	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
