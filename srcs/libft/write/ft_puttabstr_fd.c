/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttabstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:32:07 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 11:58:19 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puttabstr_fd(char **ptr, int fd)
{
	int i;

	i = 0;
	while (ptr[i] != NULL)
	{
		ft_putstr_fd(ptr[i++], fd);
		ft_putchar_fd('\n', fd);
	}
	return (i);
}
