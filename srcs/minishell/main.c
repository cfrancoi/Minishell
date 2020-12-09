/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:04 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 14:32:35 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **envp)
{
	int	ret;

	if (ac != 1)
		return (0);
	(void)av;
	if (msh_sig() == -1)
		return (-1);
	if (!(g_all.built = builtins_alloc(g_all.built, "echo", echo)))
		return (-1);
	if (!(g_all.var = get_envp(envp)))
		return (-1);
	ret = ft_prompt();
	return (ret);
}
