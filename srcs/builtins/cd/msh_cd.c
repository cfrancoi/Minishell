/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:26:35 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/15 11:47:48 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "env.h"
#include <dirent.h>
#include <sys/errno.h>

static int	is_abs_path(char *ptr)
{
	if (ptr[0] == '/')
		return (1);
	return (0);
}

static int	is_relativ_path(char *ptr)
{
	char		*cwd;
	DIR			*fdir;

	cwd = NULL;
	fdir = NULL;
	if ((cwd = getcwd(NULL, 0)) == NULL
		|| (cwd = ft_strjoinf(cwd, "/", 1)) == NULL
		|| (cwd = ft_strjoinf(cwd, ptr, 1)) == NULL
		|| (fdir = opendir(cwd)) == NULL)

	{
		if (fdir)
			free(fdir);
		if (cwd)
			free(cwd);
		return (-1);
	}
	free(fdir);
	free(cwd);
	return (1);
}

int			set_pwd_var(void)
{
	char	*path;
	t_var	*m_pwd;
	t_var	*m_oldpwd;

	if ((path = getcwd(NULL, 0)) == NULL)
		return (-1);
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
	return (0);
}

static int			msh_error_cd(char **argv)
{
		ft_putstr_fd("msh cd : ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(" : ", 2);
		ft_putendl_fd(strerror(errno), 2);
		errno = 0;
		return (256);
}

static int	get_relative(char **argv)
{
	char		*path;

	path = ft_strjoinf(getcwd(NULL, 0), "/", 1);
	path = ft_strjoinf(path, argv[1], 1);
	chdir(path);
	free(path);
	if (set_pwd_var() == -1)
		return (msh_error_cd(argv));
	return (0);
}

int			msh_cd(int ac, char **argv)
{
	(void)argv;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (is_abs_path(argv[1]))
		{
			if (chdir(argv[1]) == -1 || set_pwd_var() == -1)
				return (msh_error_cd(argv));
			else
				return (0);
		}
		if (is_relativ_path(argv[1]) == -1)
		{
			return (msh_error_cd(argv));
		}
		else
			return (get_relative(argv));
	}
	return (0);
}
