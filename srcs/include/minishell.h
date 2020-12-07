/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:26:16 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/07 18:20:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL_H
# define	MINISHELL_H

# include	<unistd.h>
# include	"./env.h"
# include	"../libft/libft.h"
# include	"./msh_parsing.h"
# include	"./builtins.h"
# include	"./msh_execve.h"
# include	"./cfrancoi.h"
# include	"./lfourage.h"
# define	MSH_READ			0
# define	MSH_STCMD			1
# define	MSH_EXIT			2
# define	ERR_EXECVE			126
# define	ERR_CMD_NOT_FOUND	127

typedef struct	s_all
{
	t_built		*built;
	t_var		*var;
	char		*path;
	int			*step;
}				t_all;

t_all			g_all;


int				ft_prompt(void);
int				msh_sig(void);
void			print_path(void);

# endif
