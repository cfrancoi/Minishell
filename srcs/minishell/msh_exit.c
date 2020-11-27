/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:57:17 by user42            #+#    #+#             */
/*   Updated: 2020/11/27 14:35:50 by cfrancoi         ###   ########lyon.fr   */
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
		if (cmd->str)
			free(cmd->str);
		ft_array_free(cmd->av);
		tofree = (void *)cmd;
		cmd = cmd->next;
		free(tofree);
	}
}

int			msh_exit(t_cmd *cmd, int ret)
{
	if (need_pipe(cmd))
		return (0);
	free_cmd(cmd);
	free_built(g_all.built);
	free_lst_var(g_all.var);
	ft_putstr_fd("exit\n", 2);
	exit(ret);
}
