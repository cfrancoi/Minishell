/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:03:16 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:03:25 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int o, size_t n)
{
	unsigned char *ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = (unsigned char)o;
	return ((void *)s);
}
