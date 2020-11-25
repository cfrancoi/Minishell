/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:26:16 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/25 13:58:26 by cfrancoi         ###   ########lyon.fr   */
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

typedef struct	s_all
{
	t_built		*built;
	t_var		*var;
	char		*path;
}				t_all;

t_all			g_all;

int				ft_prompt(void);

# endif
