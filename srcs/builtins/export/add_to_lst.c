/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:17:40 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/01 17:05:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"

static int		is_name_var(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '=' && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (str[i] == '=' || str[i] == '\0')
	{
		str[i] = 0;
		return (i);
	}
	else
		return (0);
}

static t_var	*is_existing_var(char *name)
{
	t_var *tmp;

	tmp = get_var(g_all.var, name);
	return (tmp);
}

static int		replace_content(t_var *tmp, char *ptr, int i)
{
	if (tmp->content != NULL)
		free(tmp->content);
	if ((tmp->content = ft_strdup(&ptr[i + 1])) == NULL)
		return (-1);
	return (0);
}

static int		to_add(char *ptr)
{
	int		i;
	t_var	**lst;
	t_var	*tmp;

	tmp = NULL;
	lst = &g_all.var;
	i = is_name_var(ptr);
	if (i == 0)
		return (-1);
	if ((tmp = is_existing_var(ptr)) != NULL)
	{
		if ((replace_content(tmp, ptr, i)) == -1)
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

int				add_to_lst(int ac, char **av)
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
