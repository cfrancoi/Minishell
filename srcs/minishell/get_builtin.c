/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:29:53 by user42            #+#    #+#             */
/*   Updated: 2020/11/10 16:34:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int		get_builtin(char *cmd, t_built *built, void **f)
{
	while (built->next)
	{
		if (strncmp(cmd, built->name, ft_strlen(built->name) == 0))
		{
			*f = built->f;
			return (0);
		}
		built = built->next;
	}
	*f = NULL;
	return (-1);
}