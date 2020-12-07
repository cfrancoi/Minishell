/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_sig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:22:11 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/07 15:01:40 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <stdio.h>

static void sigint_handler(int signum)
{
    char        *path;
    (void)signum;
    path = NULL;
    
    /* crt-c */
    ft_putstr_fd("\n", 1);
    if (g_all.step == MSH_READ)
    {
        path = getcwd(NULL, 0); // a securiser !!!!!!
        ft_putstr_fd("Minishell : ", 1);
		ft_putstr_fd(path, 1);
		ft_putstr_fd(" : ", 1);  /* a faire */
        free(path);
    }
    return ;
}

static void sigquit_handler(int signum)
{
    char *path;

    (void)signum;
    path = NULL;
    ft_putstr_fd("\n", 1);
    if (g_all.step == MSH_READ)
    {
        path = getcwd(NULL, 0); // a securiser !!!!!!
        ft_putstr_fd("Minishell : ", 1);
		ft_putstr_fd(path, 1);
		ft_putstr_fd(" : ", 1);  /* a faire */
        free(path);
    }
    /**/
    return ;
}

int     msh_sig()
{
    if ((signal(SIGINT, sigint_handler)) == SIG_ERR)
        return (-1);
    if ((signal(SIGQUIT, sigquit_handler)) == SIG_ERR)
        return (-1);
    return (0);
}