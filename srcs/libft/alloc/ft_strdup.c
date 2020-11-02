/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:08:07 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 12:08:08 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_memcpy(ptr, (void*)s, (len));
	ptr[len] = '\0';
	return (ptr);
}
