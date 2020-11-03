/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:14:23 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/03 17:32:37 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

void	free_lst_var(t_var *lst)
{
	t_var	*ptr;

	while (lst)
	{
		ptr = lst->next;
		if (lst->name)
			free(lst->name);
		if (lst->content)
			free(lst->content);
		free(lst);
		lst = ptr;
	}

}
