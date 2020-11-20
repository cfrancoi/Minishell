/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:17:40 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/20 17:25:48 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static int			is_name_var(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] != '=' && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (str[i] == '=' || str[i] == '\0')
		return (1);
	else
		return (0);
}

static t_var			*is_existing_var(char *name)
{
	t_var *tmp;

	tmp = get_var(g_all.var, name);

	return(tmp);
}

static int		to_add(char *ptr)
{
	int i;
	t_var	**lst;
	t_var	*tmp;

	tmp= NULL;
	lst = &g_all.var;
	i = 0;

	if (!is_name_var(ptr))
		return (-1);
	while (ptr[i + 1] && ptr[i] != '=')
		i++;
	ptr[i] = '\0';
	if ((tmp = is_existing_var(ptr)) != NULL)
	{
		//ptr[i] = '=';
		if (tmp->content != NULL)
			free(tmp->content);
		if (ft_strdup(&ptr[i + 1]) == NULL)
			return (-1);
	}
	else
	{
		if ((tmp = create_var(&ptr[0], &ptr[i + 1])) == NULL)
			return (-1);
		add_var(lst, tmp);
	}
	ptr[i] = '=';
	return (0);
}
/* En cas d'erreur un message est send sans interompre la fct */
/* 
	Exemple : export OUI!=NON NON=OUI 
	on aura un message d'erreur pour $OUI mais $NON sera cree
*/

#include <stdio.h>

int		add_to_lst(int ac, char **av) 
{
	int i;
	int ret;

	ret = 0;
	i = 1;
	while (i < ac)
	{
		if (to_add(av[i]) != 0)
		{
			ret = 1;
			ft_putstr_fd("msh : export : << ", 2);
			ft_putstr_fd(av[i], 2);
			ft_putstr_fd(" >> : identifiant non valable\n", 2);
		}
		i++;
	}
	return (ret);	
}

