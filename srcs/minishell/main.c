/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:04 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/07 18:25:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#include <stdio.h>

int		main(int ac, char **av, char **envp)
{
	int	ret;
	int	step;

	step = 0;
	g_all.step = &step;
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
