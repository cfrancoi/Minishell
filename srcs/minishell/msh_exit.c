/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:57:17 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 04:06:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_return(void)
{
	t_var	*ret;

	if ((ret = get_var(g_all.var, "?")) == NULL)
		return (-1);
	return (ft_atoi(ret->content));
}

static int	get_exit_value(t_cmd *cmd, int ret)
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
	else if (g_all.step != MSH_SIGEOF)
		msh_free(cmd, 1);
	else
		msh_free(NULL, 0);
	if (errno != 0)
		ft_putendl_fd(strerror(errno), 2);
	return (ret);
}
