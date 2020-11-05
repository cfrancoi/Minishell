/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:57:17 by user42            #+#    #+#             */
/*   Updated: 2020/11/05 16:27:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		msh_exit(t_cmd *cmd, t_arg *arg, int ret)
{
	void	*tofree;

	while (cmd)
	{
		if (cmd->str)
			free(cmd->str);
		ft_array_free(cmd->av);
		(t_cmd *)tofree = cmd;
		cmd = cmd->next;
		free(tofree);
	}
	while (arg)
	{
		if (arg->ptr)
			free(arg->ptr);
		(t_arg *)tofree = arg;
		arg = arg->next;
		free(tofree);
	}
	exit (ret);
}