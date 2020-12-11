/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:04 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/11 16:05:45 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **envp)
{
	int	ret;

	if (ac != 1)
		return (0);
	(void)av;
	g_all.built = NULL;
	g_all.path = NULL;
	g_all.var = NULL;
	if (msh_sig() == -1)
		return (EXIT_FAILURE);
	if (!(g_all.built = builtins_alloc(g_all.built, "echo", echo)))
	{
		msh_free(NULL, 1);
		return (EXIT_FAILURE);
	}
	if (!(g_all.var = get_envp(envp)))
	{
		msh_free(NULL, 1);
		return (EXIT_FAILURE);
	}
	ret = ft_prompt();
	return (ret);
}
