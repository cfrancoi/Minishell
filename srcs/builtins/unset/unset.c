/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:47 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 15:57:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/builtins.h"

int			unset(int ac, char **argv)
{
	int		i;
	int		ret;
	t_var	*var;
	t_var	*varnxt;

	i = 1;
	ret = 0;
	var = g_all.var;
	write(1, "**unset**\n", 10);
	while (i <= ac)
	{
		varnxt = get_var(var, argv[i]);
		if (varnxt)
		{
			while (varnxt && var->next != varnxt)
				var = var->next;
			cat_var(var);
		}
		var = g_all.var;
		i++;
	}
	return (ret);
}
