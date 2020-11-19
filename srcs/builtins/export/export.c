/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:21 by user42            #+#    #+#             */
/*   Updated: 2020/11/19 16:49:26 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/builtins.h"
#include <stdio.h>

int		msh_export(int ac, char **av)
{
	write(1, "**export**\n", 11);

	av = av;
	if (ac == 1)
		env();
	else
		return (13);
	return (0);
}
