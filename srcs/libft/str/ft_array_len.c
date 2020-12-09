/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 12:50:29 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 14:38:38 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_array_len(char **ptr)
{
	int i;

	i = 1;
	if (ptr == NULL)
		return (0);
	while (ptr[i] != NULL)
		i++;
	return (i);
}
