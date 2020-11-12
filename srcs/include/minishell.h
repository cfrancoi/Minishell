/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:26:16 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/12 15:33:54 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL_H
# define	MINISHELL_H

# include	<unistd.h>
# include	"../libft/libft.h"
# include	"./env.h"
# include	"./msh_parsing.h"
# include	"./builtins.h"
# include	"./msh_execve.h"
# include	"./cfrancoi.h"
# include	"./lfourage.h"


int			ft_prompt(t_built *built);

# endif
