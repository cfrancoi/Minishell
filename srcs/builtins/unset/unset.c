/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:47 by user42            #+#    #+#             */
/*   Updated: 2020/12/08 16:54:26 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
	while (++i < ac)
	{
		if (check_arg(argv[i], &ret) == 0)
		{
			varnxt = get_var(var, argv[i]);
			if (varnxt)
			{
				if (is_protect(argv[i]))
				{
					free(varnxt->content);
					varnxt->content = NULL;
					varnxt->protect = 1;
				}
				else
				{
					while (varnxt && var->next != varnxt)
						var = var->next;
					cat_var(var);
				}
			}
			var = g_all.var;
		}
	}
	return (ret);
}

int			unset_child(int ac, char **argv)
{
	if (ac == 1)
		return (EXIT_SUCCESS);
	(void)ac;
	(void)argv;
	return (EXIT_SUCCESS);
}
