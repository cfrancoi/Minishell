/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:22:11 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/01 16:35:14 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static void sigint_handler(int signum)
{
    (void)signum;
    ft_putstr_fd("crt-c\n", 1);
    return ;
}

int     msh_sig()
{
    if ((signal(SIGINT, sigint_handler)) == SIG_ERR)
        return (-1);
    return (0);
}