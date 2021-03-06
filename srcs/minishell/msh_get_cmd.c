/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:29:50 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/11 12:26:00 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**lst_to_array(t_arg *lst)
{
	t_arg	*tmp;
	int		i;
	char	**ptr;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if ((ptr = malloc(sizeof(char *) * (i + 1))))
	{
		i = 0;
		while (lst)
		{
			ptr[i++] = lst->ptr;
			tmp = lst->next;
			free(lst);
			lst = tmp;
		}
		ptr[i] = NULL;
	}
	return (ptr);
}

char			**msh_get_cmd(char *ptr)
{
	t_arg	*lst;
	char	**av;

	lst = NULL;
	get_args_ptr(ptr, &lst);
	get_args_lst(lst);
	av = lst_to_array(lst);
	return (av);
}
