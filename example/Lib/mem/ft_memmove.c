/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:03:06 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:03:08 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pt_dest;
	unsigned char	*pt_src;
	size_t			i;

	i = 0;
	pt_dest = (unsigned char*)dest;
	pt_src = (unsigned char*)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (pt_dest > pt_src)
		while (n-- > 0)
			pt_dest[n] = pt_src[n];
	else if (pt_dest < pt_src)
	{
		while (i < n && pt_dest[i])
		{
			pt_dest[i] = pt_src[i];
			i++;
		}
	}
	return ((void *)dest);
}
