/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:15:46 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/11 17:03:38 by cfrancoi         ###   ########lyon.fr   */
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
	if (cmd->sep == MSH_EOF)
		ft_putstr_fd("EOL", 2);
	else if (cmd->sep == PIPE)
		ft_putstr_fd("|", 2);
	else if (cmd->sep == SEMI)
		ft_putstr_fd(";", 2);
	else if (cmd->sep == LFT)
		ft_putstr_fd("<", 2);
	else if (cmd->sep == RGT)
		ft_putstr_fd(">", 2);
	else if (cmd->sep == DRGT)
		ft_putstr_fd(">>", 2);
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
		if (cmd->av == NULL || !cmd->av[0] || ft_strlen(cmd->av[0]) == 0)
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
	av_last_alloc(first);
	*ptr = first;
	if (msh_last_check(*ptr) == -1)
	{
		if ((edit_qmrk(2) == 0))
			return (0);
		return (-1);
	}
	return (1);
}
