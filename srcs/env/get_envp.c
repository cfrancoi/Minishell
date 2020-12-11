/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:49:41 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/11 15:47:36 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int	add_pwd(t_var **var)
{
	t_var	*tmp;

	tmp = NULL;
	if (get_var(*var, "PWD") == NULL)
	{
		if (!(tmp = create_var("PWD", getcwd(NULL, 0), 1)))
			return (-1);
		add_var(var, tmp);
	}
	if (get_var(*var, "OLDPWD") == NULL)
	{
		if (!(tmp = create_var("PWD", "", 1)))
			return (-1);
		add_var(var, tmp);
	}
	return (1);
}

t_var		*get_envp(char **envp)
{
	int		i;
	int		y;
	t_var	*var;
	t_var	*tmp;

	i = -1;
	y = 0;
	var = NULL;
	if (!(tmp = create_var("?", "0", 1)))
		return (NULL);
	add_var(&var, tmp);
	tmp = NULL;
	if (envp != NULL)
		while (envp[++i] != NULL)
		{
			while (envp[i][y] != '=')
				y++;
			envp[i][y] = '\0';
			if ((tmp = create_var(envp[i], &envp[i][y + 1], 0)) == NULL)
				return (NULL);
			add_var(&var, tmp);
			envp[i][y] = '=';
			y = 0;
		}
	add_pwd(&var);
	return (var);
}
