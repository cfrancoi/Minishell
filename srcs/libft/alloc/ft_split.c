/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:08:00 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:08:01 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	countsep(char *s, char c)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0'
				&& s[i + 1] != c)
			res++;
		i++;
	}
	if (res == 1 && s[i - 1] == c)
		return (res);
	if (s[0] == c)
		return (res);
	return (res + 1);
}

static char		*ft_next(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return ((char*)&s[i]);
	return ((char*)&s[i + 1]);
}

static char		*ft_nextit(const char *s, char c)
{
	char	*pt;
	int		n;

	n = 0;
	while (s[n] != c && s[n] != '\0')
		n++;
	if (!(pt = (char*)ft_calloc(sizeof(char), n + 1)))
		return (NULL);
	n = 0;
	while (s[n] != c && s[n] != '\0')
	{
		pt[n] = s[n];
		n++;
	}
	return (pt);
}

static int		ft_ffree(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
		free(ptr[i++]);
	free(ptr);
	return (1);
}

char			**ft_split(char const *s, char c)
{
	char		**ptr;
	const char	*spt;
	size_t		sep;
	size_t		i;

	spt = s;
	if (s == NULL)
		return (NULL);
	if (spt[0] == 0)
		return ((char**)ft_calloc(sizeof(char*), 1));
	sep = countsep((char*)s, c);
	i = 0;
	if (!(ptr = (char**)malloc(sizeof(char*) * (sep + 1))))
		return (NULL);
	while (i < sep)
	{
		if (spt[0] != c && spt[0] != '\0' && (ptr[i++] = ft_nextit(spt, c)))
			if (ptr[i - 1] == NULL && (ft_ffree(ptr)))
				return (NULL);
		spt = ft_next(spt, c);
	}
	ptr[sep] = NULL;
	return (ptr);
}
