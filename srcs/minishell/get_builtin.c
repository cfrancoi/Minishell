/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:29:53 by user42            #+#    #+#             */
/*   Updated: 2020/11/18 14:48:53 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>

int		get_builtin(char *cmd, int (**f)(), t_cmd *ptr)
{
	t_built	*built;

	built = g_all.built;	
	ptr = ptr; /* changer le prototype com for norminette <3 */
	if (ft_strncmp(cmd, "exit", 5) == 0)
		exit(10);//msh_exit(ptr, built, 8);
	while (built)
	{
		if (ft_strncmp(cmd, built->name, ft_strlen(cmd)) == 0)
		{
			*f = built->f;
			return (1);
		}
		built = built->next;
	}
	*f = NULL;
	return (0);
}
