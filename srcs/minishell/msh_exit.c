/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:57:17 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 20:09:28 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

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

static	int get_return(void)
{
	t_var	*ret;

	if ((ret = get_var(g_all.var, "?")) == NULL)
		return (-1);
	return (ft_atoi(ret->content));
}

static	int	get_exit_value(t_cmd *cmd, int ret)
{
	int		i;

	i = 0;
	if (cmd->av[1] != NULL)
	{
		while (ft_isdigit(cmd->av[1][i]))
			i++;
		if (cmd->av[1][i] == '\0')
			return (ft_atoi(cmd->av[1]));
		else
		{
			ft_putstr_fd("msh: exit: ", 2);
			ft_putstr_fd(cmd->av[1], 2);
			ft_putendl_fd(" : numerical argument required", 2);
			return (2);
		}
	}
	return (ret);
}

int			msh_exit(t_cmd *cmd)
{
	int ret;

	ft_putendl_fd("exit", 2);
	ret = get_return();
	if (g_all.step == MSH_EXIT)
		ret = get_exit_value(cmd, ret);
	free_cmd(cmd);
	free_built(g_all.built);
	free_lst_var(g_all.var);
	if (errno != 0)
		ft_putendl_fd(strerror(errno), 2);
	return (ret);
}
