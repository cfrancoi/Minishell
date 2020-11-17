/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:57:17 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 18:05:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	exit (ret);
}
