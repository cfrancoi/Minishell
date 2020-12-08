/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:50:13 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 19:00:56 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdio.h>

char	**lst_to_envp(t_var *lst)
{
	t_var	*tmp;
	int		len;
	char	**envp;
	char	*ptr;

	len = 0;
	tmp = lst;
	ptr = NULL;
	while (tmp && ++len)
       tmp = tmp->next;
	if ((envp = malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	envp[len] = NULL;
	tmp = lst;
	len = 0;
	while (tmp)
	{
		ptr = ft_strjoinf(tmp->name, "=", 0);
		ptr = ft_strjoinf(ptr, tmp->content, 1);
		envp[len++] = ptr;
		tmp = tmp->next;
	}
	return (envp);
}
