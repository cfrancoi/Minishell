/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:45:15 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/15 16:17:31 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_exit_arg(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->av[1] != NULL)
	{
		if (cmd->av[1][i] == '+' || cmd->av[1][i] == '-')
			i++;
		while (ft_isdigit(cmd->av[1][i]))
			i++;
		if (cmd->av[1][i] == '\0')
		{
			if (cmd->av[2] == NULL)
				return (1);
			else
			{
				ft_putstr_fd("msh: exit: ", 2);
				ft_putstr_fd(cmd->av[1], 2);
				ft_putendl_fd(" : too many arguments", 2);
				return (0);
			}
		}
	}
	return (1);
}

int			start_builtins(int status, t_cmd *cmd, t_tfrk *lst)
{
	if (lst->prev == NULL && lst->next == NULL)
	{
		if (ft_strncmp(cmd->av[0], "cd", 3) == 0)
			return (msh_cd(ft_array_len(cmd->av), cmd->av));
		else if (ft_strncmp(cmd->av[0], "export", 7) == 0)
			return (add_to_lst(ft_array_len(cmd->av), cmd->av));
		else if (ft_strncmp(cmd->av[0], "unset", 6) == 0)
			return (unset_parent(ft_array_len(cmd->av), cmd->av));
		else if (ft_strncmp(cmd->av[0], "exit", 5) == 0)
		{
			if (is_exit_arg(cmd))
				g_all.step = MSH_EXIT;
			else
				return (256);
		}
	}
	return (status);
}

int			child(t_cmd *ptr, char **envp)
{
	int		(*f)();
	int		ret;

	ret = 0;
	if (get_builtin(ptr, &f, envp) == 1)
	{
		ret = (*f)(ft_array_len(ptr->av), ptr->av);
		ft_array_free(envp);
		msh_free(ptr, 1);
		exit(ret);
	}
	else
	{
		if (pathfinder(ptr, envp) == -1)
		{
			if (errno != 0)
				ft_putendl_fd(strerror(errno), 2);
			ft_array_free(envp);
			exit(ERR_EXECVE);
		}
	}
	exit(ret);
}

static int	kill_all(t_tfrk *lst)
{
	msh_fork_error("wait", -1);
	while (lst)
	{
		kill(lst->pid, SIGKILL);
		lst = lst->next;
	}
	if (errno != 0)
		errno = 0;
	return (-1);
}

int			wait_all(t_tfrk *lst)
{
	int status;

	status = 0;
	while (lst != NULL)
	{
		if ((waitpid(lst->pid, &status, 0)) == -1)
			return (kill_all(lst->next));
		if (!(lst->prev) && !(lst->next))
			status = start_builtins(status, lst->cmd, lst);
		if (g_all.step != MSH_SIGINT && g_all.step != MSH_SIGQUIT)
			edit_qmrk(status / 256);
		lst = lst->next;
	}
	if (WIFSIGNALED(status))
	{
		if (WCOREDUMP(status))
			ft_putendl_fd("Core dumped", 2);
	}
	return (g_all.step);
}
