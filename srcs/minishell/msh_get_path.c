/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:07:47 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/27 15:39:19 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_next_path(char **pgrm)
{
	char	*tmp;
	char	*ptr;

	tmp = ft_strccpy(*pgrm, ':');
	if (ft_strlen(tmp) == 0)
	{
		free(tmp);
		return (NULL);
	}
	else
	{
		ptr = *pgrm;
		while (*ptr != '\0' && *ptr != ':')
		{
			ptr++;
		}
		if (*ptr == ':')
			ptr += 1;
		*pgrm = ptr;
		return (tmp);
	}
}

int				msh_get_path(char *prgm, char **path)
{
	void	*ptr;
	char	*tmp;
	int		fd;

	if ((ptr = get_var(g_all.var, "PATH")) == NULL)
		return (-1);
	ptr = ((t_var *)ptr)->content;
	while ((tmp = get_next_path((char **)(&ptr))) != NULL)
	{
		tmp = ft_strjoinf(tmp, "/", 1);
		tmp = ft_strjoinf(tmp, prgm, 1);
		if ((fd = open(tmp, O_RDONLY)) == -1)
		{
			free(tmp);
			tmp = NULL;
		}
		else
		{
			*path = tmp;
			close(fd);
			return (0);
		}
	}
	return (-1);
}
