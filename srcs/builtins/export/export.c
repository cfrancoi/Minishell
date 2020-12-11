/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:21 by user42            #+#    #+#             */
/*   Updated: 2020/12/11 14:49:27 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		msh_export(int ac, char **av)
{
	(void)av;
	if (ac == 1)
		env();
	else
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
