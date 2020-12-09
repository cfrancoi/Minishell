/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:51:47 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 04:10:00 by user42           ###   ########.fr       */
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

static void	treat_var(t_var *var, char **argv, int i)
{
	t_var	*varnxt;

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
}

int			unset_parent(int ac, char **argv)
{
	int		i;
	int		ret;
	t_var	*var;

	i = 0;
	ret = 0;
	var = g_all.var;
	while (++i < ac)
	{
		if (check_arg(argv[i], &ret) == 0)
			treat_var(var, argv, i);
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
