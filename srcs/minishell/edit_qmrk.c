/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_qmrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:41:58 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 11:49:58 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"
# include <errno.h>

static int	edit_errno(int excode, int tmp)
{
	if (excode == -1)
		errno = tmp;
	return (excode);
}

int			edit_qmrk(int excode, char *cmd)
{
	int		tmp;

	tmp = errno;
	free(g_all.var->content);
	if (!(g_all.var->content = ft_itoa_base(excode, "0123456789")))
		return (edit_errno(-1, tmp));
	if (excode == 127)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" : Command not found\n", 2);
	}
	if (excode != 0 && excode != 10)
		return (edit_errno(excode, tmp));
	return (excode);
}
