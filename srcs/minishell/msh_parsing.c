/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:15:46 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/12 14:38:45 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		msh_parsing(char *line, t_cmd **ptr)
{
	t_cmd	*first;
	t_cmd	*cmd;

	first = NULL;
	cmd = NULL;
	if (get_cmd_lst(line, &cmd) == -1)
		return (-1);
	first = cmd;

	/* remplacement des $env */

	while (cmd)
	{
		if (!(cmd->av = msh_get_cmd(cmd->str)))
			return (-1);
		cmd = cmd->next;
	}
	*ptr = first;
	return (1);
}
