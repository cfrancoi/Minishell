/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_execve.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:58:42 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 17:51:28 by user42           ###   ########.fr       */
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
int		msh_execve(t_cmd *ptr, int *p_fd, int *p_rd);
int		msh_dup_fd(t_cmd *ptr);
int		msh_get_path(char *prgm, char **path);
#endif
