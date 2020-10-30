/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:43:50 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/10/21 14:05:12 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/env.h"


int		get_cmd(int fd)
{
	char	*line;
	int		ret;

	ret = 1;
	line = NULL;
	while (ret)
	{
		
		ft_putstr_fd("Minishell :\n", 1);
		ret = get_next_line(fd, &line);
		if (ret != -1)
		{
			ft_putstr_fd(line, 1);
			lst_args(line);
			//line = rplc_env_cmd(line);
			if (ft_strncmp(line, "exit", 5) == 0)
			{
				free_lst_var(g_list);
				ret = 0;
			}
			free(line);
		}
		ft_putstr_fd("\n|", 1);
		ft_putnbr_fd(ret, 1);
		ft_putchar_fd('|', 1);
	}
	if (ret == -1)
		return (-1);

	return (1);
}
