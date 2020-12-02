/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:01:14 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/02 17:57:17 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

int			ft_prompt(void)
{
	int		ret;
	char	*line;
	t_cmd	*ptr;
	char	*path;

	ret = 1;
	ptr = NULL;
	line = NULL;
	while (ret)
	{
		g_all.step = MSH_READ;
		path = getcwd(NULL, 0); // a securiser !!!!!!
		ft_putstr_fd("Minishell : ", 1);
		ft_putstr_fd(path, 1);
		ft_putstr_fd(" : ", 1);  /* a faire */
		ret = get_next_line(0, &line);
		if (ret != 0)
		{
			g_all.step = MSH_STCMD;
			ret = msh_parsing(line, &ptr);
			msh_push_cmd(&ptr);
			ptr = NULL;
		}
		free(line);
		free(path);
	}
	return (ret);
}
