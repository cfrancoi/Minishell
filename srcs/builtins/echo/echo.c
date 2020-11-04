/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:47:39 by user42            #+#    #+#             */
/*   Updated: 2020/11/04 16:50:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/builtins.h"

int	main(int ac, char **av)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	if (ac == 1)
		return (0);
	while (++i < ac)
	{
		while (ft_strncmp(av[i], "-n", 3) == 0)
		{
			n = 1;
			i++;
		}
		ft_putstr_fd(1, av[i])
		if (i + 1 != ac)
			ft_putchar_fd(1, ' ');
	}
	if (n == 0)
		ft_putchar_fd(1, '\n');
	return (0);
}