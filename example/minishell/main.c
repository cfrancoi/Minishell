/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:29:21 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/10/29 16:24:33 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/env.h"

#include <stdio.h>
#include <limits.h>

int		main(void)
{
	add_var(&g_list, create_var("NEW", "--NEW--"));
	add_var(&g_list, create_var("FUN", "**FUN**"));
	add_var(&g_list, create_var("MORE", "++MORE++"));


	ls_var(&g_list);
	get_cmd(0);
	return (0);
}
