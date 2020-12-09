/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:45:27 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 17:30:54 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*add_args(char *ptr, t_arg **lst)
{
	t_arg	*new;
	t_arg	*tmp;

	if ((new = malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	new->next = NULL;
	new->ptr = ptr;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

int			get_args_ptr(char *ptr, t_arg **lst)
{
	int i;

	i = 0;
	if (ptr[i] != ' ' && ptr[i] != '\t')
		if (add_args(&ptr[i], lst) == NULL)
			return (-1);
	while (ptr[i])
	{
		if (ptr[i] == '"' || ptr[i] == 39)
		{
			i += pass_quotes(&ptr[i], ptr[i]);
			if (!(ptr[i]))
				return (-1);
		}
		if (((ptr[i] == ' ' || ptr[i] == '\t') && (ptr[i + 1] != '\t' && ptr[i + 1] != ' '))
			&& ptr[i + 1])
			if (add_args(&ptr[i + 1], lst) == NULL)
				return (-1);
		i++;
	}
	return (1);
}
