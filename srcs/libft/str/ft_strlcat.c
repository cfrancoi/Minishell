/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:03:57 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:03:59 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	n;

	j = ft_strlen(dst);
	n = j + ft_strlen(src);
	i = 0;
	if (size < ft_strlen(dst))
		return (size + ft_strlen(src));
	while (j < (size - 1) && src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (n);
}
