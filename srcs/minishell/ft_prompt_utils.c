/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:00:23 by user42            #+#    #+#             */
/*   Updated: 2020/12/15 13:51:55 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_path(void)
{
	ft_putstr_fd("Minishell : ", 0);
	ft_putstr_fd(g_all.path, 0);
	ft_putstr_fd(" : ", 0);
	if (errno == EBADF)
	{
		errno = 0;
	}
}
