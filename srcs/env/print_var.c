/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:00:42 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 14:31:24 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/env.h"

int		print_var(t_var *ptr)
{
	ft_putstr_fd(ptr->name, 1);
	ft_putchar_fd('=', 1);
	ft_putstr_fd(ptr->content, 1);
	ft_putchar_fd('\n', 1);
	return (1);
}
