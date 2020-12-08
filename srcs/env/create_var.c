/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 17:16:30 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 17:58:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdlib.h>

t_var		*create_var(char *name, char *content, int protect)
{
	t_var	*new;

	new = NULL;
	if (name != NULL)
	{
		if (!(new = malloc(sizeof(t_var))))
			return (NULL);
		if (name != NULL)
			new->name = ft_strdup(name);
		if (content != NULL)
			new->content = ft_strdup(content);
		new->next = NULL;
		new->protect = protect;
	}
	return (new);
}
