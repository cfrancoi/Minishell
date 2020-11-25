/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:04 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/25 14:08:49 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#include <stdio.h>

int		main(int ac, char **av, char **envp)
{
	int				ret;

	if (ac != 1)
		return (0);
	(void)av;
	/* pars envp */
	if (!(g_all.built = builtins_alloc(g_all.built, "echo", echo)))
		return (-1);
	if(!(g_all.var = get_envp(envp)))
		return (-1);
	/*			*/
	/* get currrent dir */
	g_all.path = getcwd(NULL, 0);
	printf("cwd = %s\n", g_all.path);
	/* start prompt */
	ret = ft_prompt();

	return (ret);
}
