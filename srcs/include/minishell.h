/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:26:16 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/11 12:57:52 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <errno.h>
# include "./env.h"
# include "../libft/libft.h"
# include "./msh_parsing.h"
# include "./builtins.h"
# include "./msh_execve.h"
# define MSH_READ			0
# define MSH_STCMD			1
# define MSH_EXIT			2
# define MSH_SIGINT			3
# define MSH_SIGQUIT		4
# define MSH_SIGEOF			5
# define ERR_EXECVE			126
# define ERR_CMD_NOT_FOUND	127

typedef struct	s_all
{
	t_built		*built;
	t_var		*var;
	char		*path;
	int			step;
}				t_all;

t_all			g_all;

int				ft_prompt(void);
int				msh_sig(void);
void			print_path(void);
void			free_cmd(t_cmd *cmd, int process);
void			msh_free(t_cmd *cmd, int process);

int				av_last_alloc(t_cmd *ptr);

#endif
