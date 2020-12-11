/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:04 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/11 15:50:38 by cfrancoi         ###   ########lyon.fr   */
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
		return (-1);
	if (!(g_all.built = builtins_alloc(g_all.built, "echo", echo)))
		return (msh_free(NULL, 1));
	if (!(g_all.var = get_envp(envp)))
		return (msh_free(NULL, 1));
	ret = ft_prompt();
	return (ret);
}
