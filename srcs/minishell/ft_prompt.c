/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:01:14 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/07 17:03:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	print_cwd(void)
{
	if (!(g.all.path = getcwd(NULL, 0)))
		return (-1);
	if (print_path(g.all.path) == -1)
		return (-1);
	return (0);
}

static int	msh_parse_line(char *line, t_cmd *ptr)
{
	g_all.step = MSH_STCMD;
	ret = msh_parsing(line, &ptr);
	if (msh_push_cmd(&ptr) == MSH_EXIT)
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
		if (print_cwd == -1)
			return (-1);
		ret = get_next_line(0, &line);
		if (ret != 0)
			ret = msh_parse_line(line, ptr);
		if (line)
			free(line);
		if (g.all.path)
			free(g.all.path);
	}
	msh_exit(ptr, 0);
	return (ret);
}
