/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:02:14 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:02:17 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*pt_dest;
	unsigned char		*pt_src;

	pt_dest = (unsigned char*)dest;
	pt_src = (unsigned char*)src;
	while (n-- > 0)
	{
		*pt_dest++ = *pt_src++;
		if (*(pt_dest - 1) == (unsigned char)c)
			return ((void *)pt_dest);
	}
	return (NULL);
}
