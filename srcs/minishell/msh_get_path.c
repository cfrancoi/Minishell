/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:07:47 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/10 18:54:48 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		while(*ptr != '\0' && *ptr != ':')
		{
			ptr++;
		}
		if (*ptr == ':')
			*ptr++;
		*pgrm = ptr;
		return (tmp);
	}
}

int			msh_get_path(char *prgm, char **path)
{
	void	*ptr;
	char	*tmp;
	int		fd;
	char	*to_free;

	fd = 0;
	*path = NULL;
	tmp = NULL;

	if ((ptr = get_var(g_list, "PATH")) == NULL)
		return (-1);
	ptr = ft_strdup(((t_var *)ptr)->content);
	to_free = ptr;
	while((tmp = get_next_path(&ptr)) != NULL)
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
			close (fd);
			free(to_free);
			return(0);
		}
	}
	if (tmp != NULL)
		free(tmp);
	free(to_free);
	return (-1);
}
