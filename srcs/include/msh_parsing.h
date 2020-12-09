/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parsing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 15:35:25 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 03:35:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_PARSING_H
# define MSH_PARSING_H

# include "./minishell.h"

# define MSH_EOF	0
# define PIPE		1
# define SEMI		2
# define LFT		3
# define RGT		4
# define DRGT		5

typedef	struct		s_cmd
{
	int				sep;
	char			*str;
	char			**av;
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_arg
{
	char			*ptr;
	struct s_arg	*next;
}					t_arg;

int					msh_parsing(char *line, t_cmd **ptr);
int					get_cmd_lst(char *str, t_cmd **src);
char				**msh_get_cmd(char	*ptr);
int					pass_quotes(char *str, int type);
int					need_pipe(t_cmd *cmd);
t_var				*variable(char *ptr, int *i, int *len);
int					get_args_ptr(char *ptr, t_arg **lst);
void				get_args_lst(t_arg *lst);

#endif
