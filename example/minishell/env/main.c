/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:14:33 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/10/26 18:08:11 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/env.h"

int		main(int ac, char **av)
{
	t_var un;
	t_var deux;
	t_var tr;
	
	g_list = NULL;
	
	un.content="lol";
	deux.content="pipou";
	tr.content="pipou";
	
	un.next = NULL;
	deux.next = NULL;
	tr.next = NULL;

	un.name="UN";
	deux.name="DEUX";
	tr.name="TROIS";

	t_var *try = create_var("TEST", "GG !!!");
	
	add_var(&g_list, &un);
	add_var(&g_list, &deux);
	add_var(&g_list, &tr);
	add_var(&g_list, try);

	//ls_var(&g_list);



	t_var *ptr = get_var(g_list, "TROISU");
	
	if (ptr)
		print_var(ptr);



	char *var;

	printf("[%s]\n", av[1]);
	var = get_str_var(av[1]);

	printf("[%s]\n", var);
	return (0);
}
