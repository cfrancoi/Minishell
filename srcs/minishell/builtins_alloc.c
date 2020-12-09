/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_alloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:15:35 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 14:31:37 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
	if (ft_strncmp(name, "echo", 5) == 0)
		ret->next = builtins_alloc(ret->next, "env", env);
	else if (ft_strncmp(name, "env", 3) == 0)
		ret->next = builtins_alloc(ret->next, "export", msh_export);
	else if (ft_strncmp(name, "export", 6) == 0)
		ret->next = builtins_alloc(ret->next, "unset", unset_child);
	else if (ft_strncmp(name, "unset", 5) == 0)
		ret->next = builtins_alloc(ret->next, "cd", f_msh_cd);
	else if (ft_strncmp(name, "cd", 2) == 0)
		ret->next = builtins_alloc(ret->next, "pwd", msh_pwd);
	return (first);
}
