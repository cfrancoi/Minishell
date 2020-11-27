/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:29:53 by user42            #+#    #+#             */
/*   Updated: 2020/11/27 14:07:07 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_builtin(char *cmd, int (**f)())
{
	t_built	*built;

	built = g_all.built;
	if (ft_strncmp(cmd, "exit", 5) == 0)
		exit(10);
	while (built)
	{
		if (ft_strncmp(cmd, built->name, ft_strlen(built->name)) == 0)
		{
			*f = built->f;
			return (1);
		}
		built = built->next;
	}
	*f = NULL;
	return (0);
}
