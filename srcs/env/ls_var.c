/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:08:29 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 01:40:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		ls_var(t_var **lst)
{
	t_var *tmp;

	tmp = *lst;
	if (tmp == NULL)
		return (0);
	else
	{
		while (tmp != NULL)
		{
			if (ft_strncmp(tmp->name, "?", 1) != 0)
				print_var(tmp);
			tmp = tmp->next;
		}
	}
	return (0);
}
