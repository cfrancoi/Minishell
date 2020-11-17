/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:57:17 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 16:22:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		need_pipe(t_cmd *cmd)
{
	int sep;

	sep = 0;
	while (cmd != NULL)
	{
		sep = cmd->sep;
		if (sep == LFT || sep ==  RGT || sep == DRGT)
			cmd = cmd->next;
		else if (sep == PIPE)
			return (1);
		else if (sep == SEMI || sep == EOF)
			return (0);
	}
	return (0);
}

int		msh_exit(t_cmd *cmd, t_built *built, int ret)
{
	void	*tofree;

	if (need_pipe(cmd))
		return (0);
	while (cmd)
	{
		if (cmd->str)
			free(cmd->str);
		ft_array_free(cmd->av);
		tofree = (void *)cmd;
		cmd = cmd->next;
		free(tofree);
	}
	while (built)
	{
		if (built->name)
			free(built->name);
		tofree = (void *)built;
		built = built->next;
		free(tofree);
	}
	free_lst_var(g_list);
	ft_putstr_fd("exit\n", 2);
	exit (ret);
}
