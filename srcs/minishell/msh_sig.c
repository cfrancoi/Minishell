/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:22:11 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 21:02:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void	sigint_handler(int signum)
{
	ft_putchar_fd('\n', 1);
	if (g_all.step != MSH_READ)
		g_all.step = MSH_SIGINT;
	if (edit_qmrk(128 + signum) == -1)
		ft_putendl_fd(strerror(errno), 2);
	if (g_all.step == MSH_READ)
		print_path();
	return ;
}

static void	sigquit_handler(int signum)
{
	ft_putchar_fd('\n', 1);
	if (g_all.step != MSH_READ)
		g_all.step = MSH_SIGQUIT;
	if (edit_qmrk(128 + signum) == -1)
		ft_putendl_fd(strerror(errno), 2);
	if (g_all.step == MSH_READ)
		print_path();
	return ;
}

int			msh_sig(void)
{
	if ((signal(SIGINT, sigint_handler)) == SIG_ERR)
		return (-1);
	if ((signal(SIGQUIT, sigquit_handler)) == SIG_ERR)
		return (-1);
	return (0);
}
