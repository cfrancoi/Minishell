/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:01:27 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 14:42:19 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

size_t		ft_slen(const char *ptr)
{
	size_t i;

	if (ptr == NULL || !ptr)
		return (0);
	i = 0;
	while (ptr[i] || ptr[i] != '\0')
		i++;
	return (i);
}

int			ft_istrchr(char *ptr, char c)
{
	int		i;
	int		j;

	j = ft_slen(ptr);
	i = 0;
	if (ptr == NULL)
		return (-1);
	while (i < j && ptr[i] && ptr[i] != c)
		i++;
	if (ptr[i] == c)
		return (i + 1);
	return (-1);
}

char		*ft_strjoinfree(char *start, char *end, int f)
{
	char	*nw_pt;
	size_t	i;
	size_t	j;

	i = ft_slen(start) + ft_slen(end);
	if ((nw_pt = (char *)malloc(sizeof(char) * (i + 1))))
	{
		i = 0;
		j = 0;
		while (start && start[i])
		{
			nw_pt[i] = start[i];
			i++;
		}
		while (end && end[j])
			nw_pt[i++] = end[j++];
		nw_pt[i] = '\0';
	}
	else
		f = 0;
	if (start && (f == 1 || f == 0))
		free(start);
	if (end && (f == 2 || f == 0))
		free(end);
	return (nw_pt);
}

char		*ft_strccpy(char *start, char c)
{
	char	*ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (start == NULL)
		return (ft_calloc(sizeof(char), 1));
	while (start[len] != '\0' && start[len] != c)
		len++;
	if ((ptr = (char *)malloc(sizeof(char) * (len + 1))))
	{
		while (start[i] && start[i] != c)
		{
			ptr[i] = start[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
