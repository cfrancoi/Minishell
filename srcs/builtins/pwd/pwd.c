/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:39:19 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/11 14:49:32 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int		msh_pwd(int ac, char **argv)
{
	char		*path;

	(void)ac;
	(void)argv;
	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putchar_fd('\n', 1);
	free(path);
	return (EXIT_SUCCESS);
}
