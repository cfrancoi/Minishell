/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:07:47 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/10 16:49:20 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char		*get_next_path(char **prgm)
{
	char	*tmp;

	tmp = ft_strccopy(*prgm, ':');
	if (ft_strlen(tmp) == 0)
	{
		free(tmp);
		return (NULL);
	}
	else
	{
		while(**pgrm && **prgm != ':')
		{
			*prgm++;
		}
		if (**pgrm == ':')
			*pgrm++;
		return (tmp);
	}
}

int			msh_get_path(char *prgm, char **path)
{
	t_var	*ptr;
	char	*tmp;
	int		fd;

	fd = 0;
	*path = NULL;
	tmp = NULL;
	if ((ptr = get_var(g_list, "PATH")) == NULL)
		return (-1);
	while((tmp = get_next_path(&prm)) != NULL)
	{
		tmp = ft_join(tmp, prgm, 1);
		if ((fd = open(tmp, RD_ONLY)) == -1)
		{
			free(tmp);
			tmp = NULL;
		}
		else
		{
			*path = tmp
			close (fd);
			return(0);
		}
	}
	if (tmp != NULL)
		free(tmp);
	return (-1);
}
