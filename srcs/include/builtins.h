/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:12:33 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 16:32:20 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H


typedef	struct			s_built
{
	int					(*f)(int, char **);
	char				*name;
	struct s_built		*next;
}						t_built;

# include "./env.h"
# include "./minishell.h"

int						msh_export(int ac, char **argv);
t_built					*builtins_alloc(t_built *first, char *name, int (*f)());

int						echo(int ac, char **argv);
int						env(int ac, char **argv);


int						get_builtin(char *cmd, t_built *built, int (**f)(), t_cmd *ptr);
int						msh_exit(t_cmd *cmd, t_built *built, int ret);
#endif
