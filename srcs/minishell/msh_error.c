/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:20:11 by user42            #+#    #+#             */
/*   Updated: 2020/11/09 16:38:54 by user42           ###   ########.fr       */
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
	g_list	*var;
	int		tmp;

	tmp = errno;
	free(var->content);
	if (!(var->content = ft_itoa_base(excode, "0123456789")))
		return (edit_errno(-1, tmp));
	if (excode != 0)
	{
		ft_putstr_fd(2, cmd);
		if (excode == 127)
			ft_putstr_fd(2, " : Command not found");
		else if (excode == 126)
			ft_putstr_fd(2, " : Command is not an executable");
		else if (excode >= 128)
			ft_putstr_fd(2, " : Command failed");
		return (edit_errno(excode, tmp));
	}
	return (0);
}