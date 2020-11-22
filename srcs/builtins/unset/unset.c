/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/22 18:05:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/builtins.h"
# include <stdio.h>

int	unset_parent(int ac, char **argv)
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
		varnxt = get_var(var, argv[i]);
		if (varnxt)
		{
			while (varnxt && var->next != varnxt)
				var = var->next;
			cat_var(var);
		}
		var = g_all.var;
	}
	return (ret);
}

int	unset_child(int ac, char **argv)
{
	int		i;
	t_var	*tmp;

	i = 0;
	if (ac == 1)
		return (0);
	while (++i <= ac)
	{
		tmp = get_var(g_all.var, argv[i]);
		if (tmp)
			return (14);
	}
	return (0);
}
