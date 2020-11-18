/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:21 by user42            #+#    #+#             */
/*   Updated: 2020/11/18 14:55:00 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/builtins.h"
#include <stdio.h>

static t_var	*add_to_lst(char *ptr) 
{
	int i;
	t_var	**lst;

	lst = &g_all.var;
	i = 0;
	while (ptr[i + 1] && ptr[i] != '=')
		i++;
	ptr[i] = '\0';
	t_var *tmp = create_var(&ptr[0], &ptr[i + 1]);
	print_var(tmp);
	printf("%s %s\n", tmp->name, tmp->content);
	add_var(lst, tmp);
	ls_var(lst);
	return (tmp);
}
int		msh_export(int ac, char **av)
{
	write(1, "**export**\n", 11);

	while (ac > 1)
	{
		printf("we are hre \n");
		add_to_lst(av[ac - 1]);
		ac--;
	}
	return(0);
}
