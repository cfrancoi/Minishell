/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:44:05 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 18:03:50 by user42           ###   ########.fr       */
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
