/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:08:29 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 15:57:49 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		ls_var(t_var **lst, int protect)
{
	t_var *tmp;

	tmp = *lst;
	if (tmp == NULL)
		return (0);
	else
	{
		while (tmp != NULL)
		{
			if (ft_strncmp(tmp->name, "?", 1) != 0 && tmp->protect == protect)
				print_var(tmp);
			tmp = tmp->next;
		}
	}
	return (0);
}
