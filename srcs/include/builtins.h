/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:12:33 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 14:46:57 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "t_built.h"
# include "./env.h"
# include "./minishell.h"
# include "./msh_execve.h"

int						msh_export(int ac, char **argv);
t_built					*builtins_alloc(t_built *first, char *name, int (*f)());
int						add_to_lst(int ac, char **av);
int						f_msh_cd(int	ac, char **argv);
int						echo(int ac, char **argv);
int						unset_child(int ac, char **argv);
int						unset_parent(int ac, char **argv);
int						msh_cd(int ac, char **argv);
int						msh_pwd(int ac, char **argv);
int						env(void);
int						msh_exit(t_cmd *cmd);

#endif
