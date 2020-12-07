/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_qmrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:41:58 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 18:22:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int			edit_qmrk(int excode, char *cmd)
{
	if (errno != 0)
	{
		ft_putendl_fd(strerror(errno), 2);
		errno = 0;
		if (*g_all.step == ERR_EXECVE)
			excode = *g_all.step;
	}
	free(g_all.var->content);
	if (*g_all.step == ERR_CMD_NOT_FOUND)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" : Command not found\n", 2);
		excode = *g_all.step;
	}
	if (!(g_all.var->content = ft_itoa_base(excode, "0123456789")))
		return (-1);
	*g_all.step = MSH_STCMD;
	return (excode);
}
