/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:25:43 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 15:55:21 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/builtins.h"

int			f_msh_cd(int ac, char **argv)
{
	write(1, "**cd**\n", 7);
	ac = 0;
	argv = NULL;
	return (11);
}
