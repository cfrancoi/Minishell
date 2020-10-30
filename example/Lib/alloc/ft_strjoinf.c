/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:08:14 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:08:15 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoinf(char *s1, char *s2, int tofree)
{
	char	*pt;
	size_t	i;
	size_t	j;
	size_t	nlen;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	nlen = (ft_strlen(s1) + ft_strlen(s2));
	if (!(pt = (char*)malloc(sizeof(char) * (nlen + 1))))
		return (NULL);
	while (i < nlen && s1[j] != '\0')
		pt[i++] = s1[j++];
	j = 0;
	while (i < nlen && s2[j] != '\0')
		pt[i++] = s2[j++];
	pt[i] = '\0';
	if (tofree == 1 || tofree == 3)
		free(s1);
	if (tofree == 2 || tofree == 3)
		free(s2);
	return (pt);
}
