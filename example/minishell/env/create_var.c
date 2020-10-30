/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:16:30 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/10/14 15:31:50 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./../../include/env.h"
#include <stdlib.h>

t_var		*create_var(char *name, char *content)
{
	t_var	*new;

	new = NULL;
	if(name != NULL)
	{
		if (!(new = malloc(sizeof(t_var))))
			return (NULL);
		if (name != NULL)
			new->name = strdup(name);
		if (content != NULL)
			new->content = strdup(content);
		new->next = NULL;

	}
	return (new);
}
