/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_push_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:48:44 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/26 16:42:23 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>

/*static t_cmd	*get_next_cmd(t_cmd *ptr)
{
	t_cmd	*cmd;
	int		sep;

	sep = 0;
	cmd = ptr;
	while (cmd != NULL)
	{
		sep = cmd->sep;
		if (sep == MSH_EOF)
		{
			ft_array_free(cmd->av);
			cmd->sep = 0;
			free(cmd);
			return (NULL);
		}
		else if (sep == PIPE || sep == SEMI)
			return (cmd->next);
		else if (sep == LFT || sep ==  RGT || sep == DRGT)
		{
			ptr = cmd->next;
			cmd->sep = 0;
			ft_array_free(cmd->av);
			free(cmd);
			cmd = ptr;
		}
	}
	return (NULL);
}*/
/*
static int	place_pipe(int (*p_fd)[2], int (*p_rd)[2], t_cmd *cmd)
{
	if (need_pipe(cmd))
	{
		
		if (p_rd[0][0] == 0 && p_rd[0][1] == 0)
		{
			p_rd[0][1] = 1;
			return (pipe(p_fd[0]));
		}
		else if (p_rd[1][0] == 0 && p_rd[1][1] == 0)
		{
			p_rd[1][1] = 1;
			
			return (pipe(p_fd[1]));
		}
	}
	return (0);
}

static int	cfg_pipe(int (*p_rd)[2])
{
	if (p_rd[0][1] == 1)
	{
		p_rd[0][1] = 0;
		p_rd[0][0] = 1;
	}
	else if (p_rd[1][1] == 1)
	{
		p_rd[1][1] = 0;
		p_rd[1][0] = 1;
	}
	return (0);
}
*/
/*int			msh_push_cmd(t_cmd	**ptr)
{
	t_cmd	*cmd;
	int		p_fd[2][2];
	int		p_rd[2][2];
	

	bzero(&p_rd[0], sizeof(int) * 2);
	bzero(&p_rd[1], sizeof(int) * 2);
	
	cmd = *ptr;
	crt_lst(cmd);
	while (cmd != NULL)
	{
		place_pipe(p_fd, p_rd, cmd);
		if (msh_execve(cmd, p_fd, p_rd) == 10)
			msh_exit(cmd, 0);
		cfg_pipe(p_rd);
		cmd = get_next_cmd(cmd);
	}
	return (0);
}*/

static t_cmd	*get_next_cmd(t_cmd *ptr)
{
	t_cmd	*cmd;
	int		sep;

	sep = 0;
	cmd = ptr;
	while (cmd != NULL)
	{
		sep = cmd->sep;
		if (sep == MSH_EOF)
		{
			ft_array_free(cmd->av);
			cmd->sep = 0;
			free(cmd);
			return (NULL);
		}
		else if (sep == SEMI)
			return (cmd->next);
		else if (sep == LFT || sep ==  RGT || sep == DRGT || sep == PIPE)
		{
			ptr = cmd->next;
			cmd->sep = 0;
			ft_array_free(cmd->av);
			free(cmd);
			cmd = ptr;
		}
	}
	return (NULL);
}

/*static int	place_pipe(int (*p_fd)[2], int (*p_rd)[2], t_cmd *cmd)
{
	if (need_pipe(cmd))
	{
		
		if (p_rd[0][0] == 0 && p_rd[0][1] == 0)
		{
			p_rd[0][1] = 1;
			return (pipe(p_fd[0]));
		}
		else if (p_rd[1][0] == 0 && p_rd[1][1] == 0)
		{
			p_rd[1][1] = 1;
			
			return (pipe(p_fd[1]));
		}
	}
	return (0);
}

static int	cfg_pipe(int (*p_rd)[2])
{
	if (p_rd[0][1] == 1)
	{
		p_rd[0][1] = 0;
		p_rd[0][0] = 1;
	}
	else if (p_rd[1][1] == 1)
	{
		p_rd[1][1] = 0;
		p_rd[1][0] = 1;
	}
	return (0);
}*/

/*int			msh_push_cmd(t_cmd	**ptr)
{
	t_cmd	*cmd;
	int		p_fd[2][2];
	int		p_rd[2][2];
	

	bzero(&p_rd[0], sizeof(int) * 2);
	bzero(&p_rd[1], sizeof(int) * 2);
	
	cmd = *ptr;
	crt_lst(cmd);
	while (cmd != NULL)
	{
		place_pipe(p_fd, p_rd, cmd);
		if (msh_execve(cmd, p_fd, p_rd) == 10)
			msh_exit(cmd, 0);
		cfg_pipe(p_rd);
		cmd = get_next_cmd(cmd);
	}
	return (0);
}
*/

/*
	need previous	p fd[0] -> close when use
	and actual		a fd[1] -> close when use
					a fd[0] -> close


*/
static int			is_builtins(int status, t_cmd *cmd)
{
	int tmp;

	tmp = status / 256;
	if (tmp == 11)
		return (msh_cd(ft_array_len(cmd->av), cmd->av));
	else if (tmp == 12)
		return (status);
	else if (tmp == 13)
		return (add_to_lst(ft_array_len(cmd->av), cmd->av));
	else if (tmp == 14)
		return (unset_parent(ft_array_len(cmd->av), cmd->av));
	return (status);
}
static int		wait_all(t_tfrk *lst)
{
	int status;

	status = 0;
	while (lst != NULL)
	{
		waitpid(lst->pid, &status, 0);
		status = is_builtins(status, lst->cmd); /* a fair */
		edit_qmrk(status / 256, lst->cmd->av[0]); /* a faire */
		lst = lst->next;
	}
	return (1);
}
static int		red_pipe(t_tfrk *lst)
{
	if (lst->prev != NULL)
	{
		if ((dup2(lst->prev->pfd[0], 0)) == -1)
			return (-1);
		close(lst->prev->pfd[0]); // fermer pere et fils
	}
	if (lst->pfd[1] != 0)
	{
		if ((dup2(lst->pfd[1], 1)) == -1)
			return (-1);
	}
	if (lst->pfd[0] != 0)
		close(lst->pfd[0]); // fermer juste dans le fils
	if (lst->pfd[1] != 0)
		close(lst->pfd[1]); // fermer dans pere et fils
	return (0);
}
static int		start_pipe(t_tfrk *lst)
{
	if ((pipe(lst->pfd) == -1))
		return (-1);
	else
		return (0);
}
static int		start_fork(t_tfrk *lst)
{
	t_tfrk	*first;
	char	*path;
	char 	**envp;
	
	path = NULL;
	first = lst;
	if ((envp = lst_to_envp(g_all.var)) == NULL)
		return (-1);
	while (lst != NULL)
	{
		if (lst->next != NULL)
			if (start_pipe(lst) == -1)
				return (-1); /* kill all fork if failed */
		printf("argv = %s pipe[0] = %i [1] = %i\n", lst->cmd->av[0], lst->pfd[0], lst->pfd[1]);
		if ((lst->pid = fork()) == -1)
		{
			return (-1); /* kill all fork if failed */
		}
		else if (lst->pid == 0)
		{
			red_pipe(lst);
			msh_dup_fd(lst->cmd);
			child(lst->cmd, path, envp); // add envp is need  
			exit(0);
		}
		else
		{
			if (lst->prev != NULL)
				close(lst->prev->pfd[0]);
			if (lst->pfd[1] != 0)
				close(lst->pfd[1]);
			lst = lst->next;
		}
	}
	ft_array_free(envp);
	return(wait_all(first));
}

int			msh_push_cmd(t_cmd	**ptr)
{
	t_cmd	*cmd;
	t_tfrk	*lst;

	cmd = *ptr;
	while (cmd != NULL)
	{
		lst = crt_lst(cmd); /* lst of cmd to fork */
		/*	*/
		start_fork(lst);
		/* free lst */
		cmd = get_next_cmd(cmd);

	}
	return (0);
}

