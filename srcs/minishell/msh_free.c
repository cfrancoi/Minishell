/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:58:57 by user42            #+#    #+#             */
/*   Updated: 2020/12/08 20:51:36 by user42           ###   ########.fr       */
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

void		free_cmd(t_cmd *cmd, int process)
{
	void	*tofree;

	while (cmd)
	{
		if (process++ != 0)
			ft_array_free(cmd->av);
		tofree = (void *)cmd;
		cmd = cmd->next;
		free(tofree);
	}
}

void		msh_free(t_cmd *cmd, int process)
{
	free_cmd(cmd, process);
	free_built(g_all.built);
	g_all.built = NULL;
	if (g_all.var != NULL)
	free_lst_var(g_all.var);
	g_all.var = NULL;
	if (g_all.path != NULL)
		free(g_all.path);
	g_all.path = NULL;
}