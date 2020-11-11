/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:12:33 by user42            #+#    #+#             */
/*   Updated: 2020/11/11 13:36:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

typedef	struct			s_built
{
	int					(*f)(int, char **);
	char				*name;
	struct s_built		*next;
}						t_built;

t_built					*builtins_alloc(t_built *first, char *name, int (*f)());
int						get_builtin(char *cmd, t_built *built, int (**f)());

int						echo(int ac, char **argv);

#endif
