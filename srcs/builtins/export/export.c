/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:21 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 17:51:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/builtins.h"
#include <stdio.h>

static t_var	*add_to_lst(char *ptr) 
{
	int i;

	i = 0;
	while (ptr[i + 1] && ptr[i] != '=')
		i++;
	ptr[i] = '\0';
	t_var *tmp = create_var(&ptr[0], &ptr[i + 1]);
	printf("%s %s\n", tmp->name, tmp->content);
	return (tmp);
}
int		msh_export(int ac, char **av)
{
	while (ac > 1)
	{
		add_var(&(g_all.var), add_to_lst(av[ac - 1]));
		ac--;
	}
	return(0);
}
