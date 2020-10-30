/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:21:09 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/10/22 15:09:42 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MINISHELL_H
# define	MINISHELL_H
#include "../Lib/libft.h"

typedef struct		s_args
{
	char			*ptr;
	char			quote;
	unsigned int	start;
	struct s_args	*next;
}					t_args;

int		get_cmd(int fd);
char	*rplc_env_cmd(char *ptr);
char	**lst_args(char *line);

# endif
