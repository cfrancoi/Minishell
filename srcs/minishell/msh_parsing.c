/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:15:46 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/27 15:41:28 by cfrancoi         ###   ########lyon.fr   */
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
	while (cmd)
	{
		if (!(cmd->av = msh_get_cmd(cmd->str)))
			return (-1);
		cmd = cmd->next;
	}
	*ptr = first;
	return (1);
}
