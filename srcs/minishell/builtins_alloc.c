/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:15:35 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 16:32:11 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/builtins.h"

t_built		*builtins_alloc(t_built *first, char *name, int (*f)())
{
	t_built	*ret;

	if (!(ret = malloc(sizeof(t_built))))
		return (NULL);
	first = ret;
	ret->next = NULL;
	ret->f = f;
	if (!(ret->name = ft_strdup(name)))
		return (NULL);
	
	//if (ft_strncmp(name, "echo", 5) == 0)
	//	ret->next = builtins_alloc(ret->next, "env", &env);
	//else if (ft_strncmp(name, "cd", 3) == 0)
	//	ret->next = builtins_alloc(ret->next, "env", &env);
	//else if (ft_strncmp(name, "env", 4) == 0)
	//	ret->next = builtins_alloc(ret->next, "export", &export);
	//else if (ft_strncmp(name, "export", 7) == 0)
	//	ret->next = builtins_alloc(ret->next, "pwd", &pwd);
	if (ft_strncmp(name, "echo", 5) == 0)
	{
		ret->next = builtins_alloc(ret->next, "env", &env);
	}
	else if (ft_strncmp(name, "env", 3) == 0)
	{
		ret->next = builtins_alloc(ret->next, "export", &msh_export);
	}

	

	//enlever lorsque les builtins seront tous integre
	//ret->next = NULL;
	//
	
	return (first);
}
