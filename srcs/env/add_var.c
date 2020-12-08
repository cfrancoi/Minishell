/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:02:19 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 15:17:05 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	add_var(t_var **lst, t_var *to_add)
{
	t_var	*tmp;

	tmp = *lst;

	if (tmp == NULL)
	{
		*lst = to_add;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = to_add;
	}
	return (0);
}
