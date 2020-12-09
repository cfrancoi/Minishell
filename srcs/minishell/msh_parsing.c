/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:15:46 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 18:41:50 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_syntax(t_cmd *cmd, t_cmd *save, int last)
{
	if (last == SEMI && cmd->sep == MSH_EOF)
	{
		free_cmd(save->next, 1);
		save->next = NULL;
		save->sep = MSH_EOF;
		return (1);
	}
	ft_putstr_fd("Minishell: syntax error < ", 2);
	ft_putendl_fd(" >", 2);
	return (-1);
}

static int	msh_last_check(t_cmd *cmd)
{
	int		last;
	t_cmd	*save;

	save = NULL;
	if ((ft_strlen(cmd->av[0]) == 0 && cmd->sep == MSH_EOF))
		return (-1);
	last = cmd->sep;
	while (cmd)
	{
		if (cmd->av == NULL || ft_strlen(cmd->av[0]) == 0)
			return (check_syntax(cmd, save, last));
		save = cmd;
		last = cmd->sep;
		cmd = cmd->next;
	}
	return (1);
}

int			msh_parsing(char *line, t_cmd **ptr)
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
	return (msh_last_check(*ptr));
}
