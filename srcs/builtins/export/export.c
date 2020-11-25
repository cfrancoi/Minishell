/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:21 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 11:19:59 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/builtins.h"
#include <stdio.h>

int		msh_export(int ac, char **av)
{
	write(1, "**export**\n", 11);

	av = NULL;
	if (ac == 1)
		env();
	else
		return (13);
	return (0);
}
