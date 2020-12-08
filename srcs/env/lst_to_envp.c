/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:50:13 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 01:52:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	**lst_to_envp(t_var *lst)
{
	t_var	*tmp;
	int		len;
	char	**envp;
	char	*ptr;

	len = 0;
	tmp = lst;
	ptr = NULL;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	if ((envp = malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	envp[len] = NULL;
	tmp = lst;
	len = 0;
	while(tmp)
	{
		ptr = ft_strjoinf(tmp->name, "=", 0);
		ptr = ft_strjoinf(ptr, tmp->content, 1);
		envp[len++] = ptr;
		tmp = tmp->next;
	}
	return (envp);
}
