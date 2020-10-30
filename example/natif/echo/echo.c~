/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:42:34 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/10/10 17:54:36 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int		main(int ac, char **av)
{
	int opt_n = 1;
	int i = 1;


	if(ac == 2)
		write(1, "lol\n", 4);

	if (ac > 1)
		while (i < ac)
			{
				write(1, av[i], strlen(av[i]));
				i++;
			}
	
	if (opt_n == 1)
		write(1, "\n", 1);
	return (0);
}
