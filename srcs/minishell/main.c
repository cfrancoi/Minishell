/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 13:52:04 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/10 16:48:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

#include <stdio.h>

int		main(int ac, char **av, char **envp)
{
	int		ret;
	t_built	*built;

	/* pars envp */
	if (!(built = builtins_alloc(built, "echo", &echo)))
		return (-1)
	get_envp(envp);
	/*			*/

	/* get currrent dir */

	/* start prompt */
	ret = ft_prompt();

	return (ret);
}
