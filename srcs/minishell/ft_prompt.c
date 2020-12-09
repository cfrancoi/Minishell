/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:01:14 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 16:57:32 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_cwd(void)
{
	if (!(g_all.path = getcwd(NULL, 0)))
		return (-1);
	print_path();
	return (0);
}

static int	msh_treat_line(char *line, t_cmd **ptr)
{
	int ret;

	g_all.step = MSH_STCMD;
	ret = msh_parsing(line, ptr);
	if (line)
		free(line);
	if (ret == -1 && *ptr != NULL)
		free_cmd(*ptr, 1);
	if (ret != -1)
		if (msh_push_cmd(ptr) == MSH_EXIT)
			ret = 0;
	return (ret);
}

int			ft_prompt(void)
{
	int		ret;
	char	*line;
	t_cmd	*ptr;

	ret = 1;
	ptr = NULL;
	line = NULL;
	while (ret)
	{
		g_all.step = MSH_READ;
		if (print_cwd() == -1)
			return (-1);
		ret = get_next_line(0, &line);
		if (ret != 0)
			ret = msh_treat_line(line, &ptr);
		else
			g_all.step = MSH_SIGEOF;
		if (g_all.path)
			free(g_all.path);
		g_all.path = NULL;
	}
	if (line != NULL && g_all.step == MSH_SIGEOF)
		free(line);
	return (msh_exit(ptr));
}
