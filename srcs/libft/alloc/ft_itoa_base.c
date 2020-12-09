/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:07:53 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 14:39:17 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		buflen(long long int nb, int len)
{
	int ret;

	ret = 1;
	if (nb >= len)
	{
		ret += (buflen((nb / len), len));
	}
	return (ret);
}

char			*ft_itoa_base(long long int nb, char *base)
{
	int		len;
	int		blen;
	int		neg;
	char	*buffer;

	buffer = NULL;
	blen = (nb < 0) ? 1 : 0;
	neg = (nb < 0) ? -1 : 1;
	len = ft_strlen(base);
	blen += buflen((long int)(nb * neg), len);
	if ((buffer = (char *)ft_calloc(sizeof(char), (blen + 1))))
	{
		buffer[blen] = '\0';
		(nb < 0) ? buffer[0] = '-' : 0;
		nb = nb * neg;
		while (--blen > -1 && buffer[blen] != '-')
		{
			buffer[blen] = base[(nb % len)];
			nb = nb / len;
		}
	}
	return (buffer);
}
