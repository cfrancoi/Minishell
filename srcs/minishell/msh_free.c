/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:58:57 by user42            #+#    #+#             */
/*   Updated: 2020/12/08 13:24:16 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_built(t_built *built)
{
	void	*tofree;

	while (built)
	{
		if (built->name)
			free(built->name);
		tofree = (void *)built;
		built = built->next;
		free(tofree);
	}
}

static void	free_cmd(t_cmd *cmd)
{
	void	*tofree;

	while (cmd)
	{
		ft_array_free(cmd->av);
		tofree = (void *)cmd;
		cmd = cmd->next;
		free(tofree);
	}
}

void		msh_free(t_cmd *cmd)
{
	free_cmd(cmd);
	free_built(g_all.built);
	g_all.built = NULL;
	free_lst_var(g_all.var);
	g_all.var = NULL;
	if (g_all.path != NULL)
		free(g_all.path);
	g_all.path = NULL;
}