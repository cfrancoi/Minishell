/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:00:23 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 14:32:11 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_path(void)
{
	ft_putstr_fd("Minishell : ", 1);
	ft_putstr_fd(g_all.path, 1);
	ft_putstr_fd(" : ", 1);
}
