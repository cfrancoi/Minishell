/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:49:41 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/04 15:17:15 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"
#include "../include/minishell.h"


int		get_envp(char **envp)
{
	int		i;
	int		y;
	t_var	*tmp;

	i = 0;
	y = 0;

	while (envp[i] != NULL)
	{
		while(envp[i][y] != '=')
			y++;
		envp[i][y] = '\0';
		if ((tmp = create_var(envp[i], &envp[i][y + 1])) == NULL)
			return (-1);
		add_var(&g_list, tmp);
		envp[i][y] = '=';
		tmp = NULL;
		y = 0;
		i++;
	}
	ls_var(&g_list);
	return (0);
}


/*int main (int ac, char **av, char **envp)
{
	int i = 0;
	get_envp(envp);
	return(0);
}*/
