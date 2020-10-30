/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:08:20 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:08:29 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;
	char	*pt;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	i = 0;
	ptr = (char*)&s[start];
	if (!(pt = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (ptr[i] && i < len)
	{
		pt[i] = ptr[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
