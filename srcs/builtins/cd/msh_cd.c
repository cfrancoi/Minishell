/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:26:35 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/07 17:55:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/builtins.h"
#include "env.h"
#include <dirent.h>
#include <stdio.h>
#include <sys/errno.h>

static int	is_abs_path(char *ptr)
{
	if (ptr[0] == '\\')
		return (1);
	return (0);
}

static int	is_relativ_path(char *ptr)
{
	char		*cwd;
	DIR			*fdir;

	if ((cwd = getcwd(NULL, 0)) == NULL)
		return (-1);
	if ((cwd = ft_strjoinf(cwd, "/", 1)) == NULL)
		return (-1);
	if ((cwd = ft_strjoinf(cwd, ptr, 1)) == NULL)
		return (-1);
	if ((fdir = opendir(cwd)) == NULL)
		return (-1);
	free(fdir);
	free(cwd);
	return (1);
}

static void	msh_error_str(char *path)
{
	ft_putstr_fd("msh cd : ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(" : ", 2);
	ft_putendl_fd(strerror(errno), 2);
}

/* fact chelou a faire des test pour vois unse PWD & OLDPWD 
		de plus $PWD affichera toujours les varable d'environement */

static void		set_pwd_var(char *path)
{
	t_var	*m_pwd;
	t_var	*m_oldpwd;
	
	
	m_pwd = NULL;
	m_oldpwd = NULL;
	if ((m_pwd = get_var(g_all.var, "PWD")) != NULL)
	{
		if ((m_oldpwd = get_var(g_all.var, "OLDPWD")) != NULL)
		{
			free(m_oldpwd->content);
			m_oldpwd->content = m_pwd->content;
		}
		else
			m_oldpwd->content = m_pwd->content;
		m_pwd->content = path;
	}
	else
		free(path);
}

int			msh_cd(int ac, char **argv)
{
	char		*path;

	(void)argv;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (is_abs_path(argv[1]))
		{
			if (chdir(argv[1]) == -1)
				return (-1);
			else
				return (0);
		}
		if (is_relativ_path(argv[1]) == -1)
			msh_error_str(argv[1]);
		else
		{
			path = ft_strjoinf(getcwd(NULL, 0), "/", 1);
			path = ft_strjoinf(path, argv[1], 1);
			chdir(path);
			set_pwd_var(path);
			return (0);
		}
	}
	return (0);
}
