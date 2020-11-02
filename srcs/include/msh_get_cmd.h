/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_cmd.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:24:17 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/02 16:29:47 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef			MSH_GET_CMD_H
# define		MSH_GET_CMD_H

# include "./minishell.h"

typedef struct	s_arg
{
	char			*ptr;

	struct s_arg	*next;
}				t_arg;

char		**msh_get_cmd(char	*ptr);

#endif
