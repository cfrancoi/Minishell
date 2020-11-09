/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_qmrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:41:58 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 17:52:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/minishell.h"
# include <errno.h>

static int	edit_errno(int excode, int tmp)
{
	if (excode == -1)
		errno = tmp;
	return (-1);
}

int			edit_qmrk(int excode, char *cmd)
{
	t_var	*var;
	int		tmp;

	var = g_list;
	tmp = errno;
	free(var->content);
	if (!(var->content = ft_itoa_base(excode, "0123456789")))
		return (edit_errno(-1, tmp));
	if (excode != 0)
	{
		ft_putstr_fd(cmd, 2);
		if (excode == 127)
			ft_putstr_fd(" : Command not found", 2);
		else if (excode == 126)
			ft_putstr_fd(" : Command is not an executable", 2);
		else if (excode >= 128)
			ft_putstr_fd(" : Command failed", 2);
		return (edit_errno(excode, tmp));
	}
	return (0);
}