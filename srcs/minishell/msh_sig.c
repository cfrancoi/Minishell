/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:22:11 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/01 18:03:47 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void sigint_handler(int signum)
{
    (void)signum;
    return ;
}

static void sigquit_handler(int signum)
{
    (void)signum;

    ft_putstr_fd("crtl-\\\n", 1);
    return ;
}

static void sigkill_handler(int signum)
{
    (void)signum;

    ft_putstr_fd("crtl-d\n", 1);
    exit(-1);
}

int     msh_sig()
{
    if ((signal(SIGINT, sigint_handler)) == SIG_ERR)
        return (-1);
    if ((signal(SIGQUIT, sigquit_handler)) == SIG_ERR)
        return (-1);
    if ((signal(15, sigkill_handler)) == SIG_ERR)
        return (-1);
    return (0);
}