/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:03:34 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/06/14 16:05:26 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atol(const char *nptr)
{
	long	i;
	long	b;
	long	n;

	n = 0;
	i = 0;
	b = 1;
	while (((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if ((nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			b = -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		n = (n * 10) + (nptr[i] - 48);
		i++;
	}
	return (n * b);
}
