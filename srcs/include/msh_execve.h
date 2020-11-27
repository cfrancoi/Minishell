/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:58:42 by user42            #+#    #+#             */
/*   Updated: 2020/11/27 16:11:56 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_EXECVE_H
#define MSH_EXECVE_H

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct          s_tfrk {
	int                 pid;
	t_cmd               *cmd;
	int                 pfd[2];
	struct s_tfrk        *prev; // to get previous pipe
	struct s_tfrk        *next;
}                       t_tfrk;

t_tfrk      *crt_lst(t_cmd *cmd);
int         child(t_cmd *ptr, char *path, char **envp);
int         msh_push_cmd(t_cmd **ptr);
int         start_fork(t_tfrk *lst);
int         msh_execve(t_cmd *ptr, int (*p_fd)[2], int (*p_rd)[2]);
int         msh_dup_fd(t_cmd *ptr);
int         red_pipe(t_tfrk *lst);
int         msh_get_path(char *prgm, char **path);
#endif
