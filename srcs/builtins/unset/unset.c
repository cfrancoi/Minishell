/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/27 13:54:20 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include <stdio.h>

static int	check_arg(char *argv, int *ret)
{
	int x;

	x = 0;
	while (argv && argv[x])
	{
		if ((ft_isalnum(argv[x]) == 0) && argv[x] != '_')
		{
			*ret = 1;
			ft_putstr_fd("unset « ", 2);
			ft_putstr_fd(argv, 2);
			ft_putstr_fd(" » : non valable identifier\n", 2);
			return (1);
		}
		x++;
	}
	return (0);
}

int			unset_parent(int ac, char **argv)
{
	int		i;
	int		ret;
	t_var	*var;
	t_var	*varnxt;

	i = 0;
	ret = 0;
	var = g_all.var;
	write(1, "**unset**\n", 10);
	while (++i < ac)
	{
		if (check_arg(argv[i], &ret) == 0)
		{
			varnxt = get_var(var, argv[i]);
			if (varnxt)
			{
				while (varnxt && var->next != varnxt)
					var = var->next;
				cat_var(var);
			}
			var = g_all.var;
		}
	}
	return (ret);
}

int			unset_child(int ac, char **argv)
{
	if (ac == 1)
		return (0);
	(void)ac;
	(void)argv;
	return (14);
}
