/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:02:43 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:02:46 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	i = 0;
	pt1 = (unsigned char*)s1;
	pt2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while ((n - 1) > i && pt1[i] == pt2[i])
		i++;
	return ((int)(pt1[i] - pt2[i]));
}
