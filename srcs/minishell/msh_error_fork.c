/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_error_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:59:59 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 00:15:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_execve.h"

int		msh_fork_error(char *cmd, int ret)
{
	if (errno != 0)
	{
		ft_putstr_fd("msh: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	return (ret);
}
