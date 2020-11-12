/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:29:50 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/12 15:04:58 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	**lst_to_array(t_arg *lst)
{
	t_arg	*tmp;
	int		i;
	char	**ptr;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}	
	if ((ptr = malloc(sizeof(char *) * (i + 1))))
	{
		i = 0;
		while(lst)
		{
			ptr[i++] = lst->ptr;
			tmp = lst->next;
			free(lst);
			lst = tmp;
		}
		ptr[i] = NULL;
	}
	return (ptr);
}

char		**msh_get_cmd(char *ptr)
{
	t_arg	*lst;
	char	**av;
	
	lst = NULL;

	get_args_ptr(ptr, &lst);
	get_args_lst(lst); /* need to free /!\ */
	//free(lst);
	av = lst_to_array(lst);


	return (av);
}

/*
int main(int ac, char **av)
{
	char **lol = msh_get_cmd(av[1]);

	int i = 0;

	while(lol[i])
	{
		printf("av[%i] = %s\n", i, lol[i]);
		i++;
	}
}
*/
