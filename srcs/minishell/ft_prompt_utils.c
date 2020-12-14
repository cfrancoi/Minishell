/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:00:23 by user42            #+#    #+#             */
/*   Updated: 2020/12/14 15:32:26 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void	print_path(void)
{
	struct stat buf;
	
	if (fstat(0, &buf) != -1)
	{
		ft_putstr_fd("Minishell : ", 0);
		ft_putstr_fd(g_all.path, 0);
		ft_putstr_fd(" : ", 0);
	}
	if (errno == EBADF)
	{
		errno = 0;
	}
}
