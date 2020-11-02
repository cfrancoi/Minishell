/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:03:43 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:03:46 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;
	size_t		i;

	i = 0;
	ptr = s;
	while (ptr[i])
	{
		if (ptr[i] == c)
			return ((char*)&ptr[i]);
		i++;
	}
	if (ptr[i] == c)
		return ((char*)&ptr[i]);
	return (NULL);
}
