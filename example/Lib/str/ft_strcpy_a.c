/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:32:07 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:06:05 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_strcpy_a(char **to_copy)
{
	int		len;
	int		i;
	char	**array;

	i = 0;
	len = 0;
	while (to_copy[len] != NULL)
		++len;
	if ((array = malloc(sizeof(char *) * (len + 1))) != NULL)
	{
		while (i < len)
		{
			array[i] = ft_strdup(to_copy[i]);
			if (array[i] == NULL)
			{
				ft_array_free(array);
				return (NULL);
			}
			++i;
		}
		array[i] = NULL;
	}
	return (array);
}
