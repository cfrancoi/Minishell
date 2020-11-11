/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:29:53 by user42            #+#    #+#             */
/*   Updated: 2020/11/11 15:45:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		get_builtin(char *cmd, t_built *built, int (**f)())
{
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
