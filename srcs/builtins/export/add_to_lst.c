/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:17:40 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/19 16:56:31 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static t_var		*to_add(char *ptr)
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
	add_var(lst, tmp);
	return (tmp);
}

int		add_to_lst(int ac, char **av) 
{
	while (ac > 1)
	{
		to_add(av[ac - 1]);
		ac--;
	}
	return (0);	
}

