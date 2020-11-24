/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:58:42 by user42            #+#    #+#             */
/*   Updated: 2020/11/24 16:47:45 by cfrancoi         ###   ########lyon.fr   */
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

int		msh_push_cmd(t_cmd **ptr);
int		msh_execve(t_cmd *ptr, int (*p_fd)[2], int (*p_rd)[2]);
int		msh_dup_fd(t_cmd *ptr);
int		msh_get_path(char *prgm, char **path);
#endif
