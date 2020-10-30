/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:04:22 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:04:23 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_chrchr(char src, char fd)
{
	if (src == fd)
		return (1);
	return (0);
}

char		*ft_strnstr(const char *src, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *)src);
	while (i < len && src[i])
	{
		while (to_find[j] && ft_chrchr((char)src[i + j], (char)to_find[j])
				&& j + i < len)
			j++;
		if (to_find[j] == '\0')
			return ((char *)&src[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
