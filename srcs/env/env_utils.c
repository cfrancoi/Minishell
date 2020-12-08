/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:15:49 by user42            #+#    #+#             */
/*   Updated: 2020/12/08 18:00:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	del_var(t_var *lst)
{
	if (lst->name)
		free(lst->name);
	if (lst->content)
		free(lst->content);
	free(lst);
}

void		cat_var(t_var *lst)
{
	t_var	*tofree;
	t_var	*tocat;

	tofree = lst->next;
	if (tofree)
	{
		tocat = tofree->next;
		del_var(tofree);
		lst->next = tocat;
	}
}

void		free_lst_var(t_var *lst)
{
	t_var	*ptr;

	while (lst)
	{
		ptr = lst->next;
		del_var(lst);
		lst = ptr;
	}
}

int			is_protect(char *name)
{
	if (ft_strncmp(name, "PWD", 4) == 0)
		return (1);
	if (ft_strncmp(name, "OLDPWD", 7) == 0)
		return (1);
	return (0);
}
