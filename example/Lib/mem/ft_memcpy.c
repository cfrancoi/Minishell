/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:02:54 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:02:56 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char *ptr;
	unsigned char *pt;

	ptr = (unsigned char*)dest;
	pt = (unsigned char*)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n-- > 0)
		*ptr++ = *pt++;
	return ((void *)dest);
}
