/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:12:33 by user42            #+#    #+#             */
/*   Updated: 2020/11/10 17:52:49 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef	struct			s_builtins
{
	void				*f;
	char				*name;
	struct s_builtins	*next;
}						t_built;

t_built					*builtins_alloc(t_built *first, char *name, void *f);
int						get_builtin(char *cmd, t_built *built, void **f);

int						echo(int ac, char **argv);

#endif
