/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:01:14 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/07 16:19:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (print_path == -1)
			return (-1);
		ret = get_next_line(0, &line);
		if (ret != 0)
		{
			g_all.step = MSH_STCMD;
			ret = msh_parsing(line, &ptr);
			if (msh_push_cmd(&ptr) == MSH_EXIT)
				ret = 0;
		}
		if (line)
			free(line);
	}
	msh_exit(ptr, 0);
	return (ret);
}
