/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:58:57 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 18:25:49 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_built(t_built *built)
{
	t_built	*tofree;

	while (built)
	{
		if (built->name)
			free(built->name);
		tofree = built;
		built = built->next;
		free(tofree);
	}
}

void		free_cmd(t_cmd *cmd, int process)
{
	t_cmd	*tofree;

	while (cmd)
	{
		if (process++ != 0)
		{
			if (cmd->av)
				ft_array_free(cmd->av);
			cmd->av = NULL;
		}
		tofree = cmd;
		cmd = cmd->next;
		free(tofree);
	}
	cmd = NULL;
}

void		msh_free(t_cmd *cmd, int process)
{
	if (cmd)
		free_cmd(cmd, process);
	cmd = NULL;
	if (g_all.built)
		free_built(g_all.built);
	g_all.built = NULL;
	if (g_all.var)
		free_lst_var(g_all.var);
	g_all.var = NULL;
	if (g_all.path)
		free(g_all.path);
	g_all.path = NULL;
}
