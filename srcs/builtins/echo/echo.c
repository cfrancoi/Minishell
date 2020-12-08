/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:47:39 by user42            #+#    #+#             */
/*   Updated: 2020/12/08 16:53:18 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	echo(int ac, char **av)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	while (++i < ac)
	{
		while (ft_strncmp(av[i], "-n", 3) == 0)
		{
			n = 1;
			i++;
		}
		ft_putstr_fd(av[i], 1);
		if (i + 1 != ac)
			ft_putchar_fd(' ', 1);
	}
	if (n == 0)
		ft_putchar_fd('\n', 1);
	return (EXIT_SUCCESS);
}
