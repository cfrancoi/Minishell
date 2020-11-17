/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:49:41 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/17 17:52:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"
#include "../include/minishell.h"
#include <stdio.h>


t_var		*get_envp(char **envp)
{
	int		i;
	int		y;
	t_var	*var;
	t_var	*tmp;

	i = 0;
	y = 0;

	var = NULL;
	if (!(tmp = create_var("?", "0")))
		return (NULL);
	add_var(&var, tmp);
	tmp = NULL;
	while (envp[i] != NULL)
	{
		while(envp[i][y] != '=')
			y++;
		envp[i][y] = '\0';
		if ((tmp = create_var(envp[i], &envp[i][y + 1])) == NULL)
			return (NULL);
		add_var(&var, tmp);
		envp[i][y] = '=';
		y = 0;
		i++;
	}
	return (var);
}


/*int main (int ac, char **av, char **envp)
{
	int i = 0;
	get_envp(envp);
	return(0);
}*/
