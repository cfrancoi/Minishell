/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:44:05 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 14:30:49 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_var	*get_var(t_var *lst, char *name)
{
	int len;

	len = ft_strlen(name);
	if (name == NULL)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->name != NULL)
			if (ft_strncmp(name, lst->name, len) == 0)
				return (lst);
		lst = lst->next;
	}
	return (NULL);
}
