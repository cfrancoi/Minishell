/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_dup_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:37:21 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/09 14:32:47 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	redirect_fd(const char *path, int flags, int fd)
{
	int lfd;

	if ((lfd = open(path, flags, 0666)) == -1)
		return (-1);
	if ((dup2(lfd, fd)) == -1)
		return (-1);
	return (close(lfd));
}

int			msh_dup_fd(t_cmd *ptr)
{
	while (ptr)
	{
		if (ptr->sep == LFT || ptr->sep == RGT || ptr->sep == DRGT)
		{
			if (ptr->next)
			{
				if (ptr->sep == LFT)
					redirect_fd(ptr->next->av[0], O_RDWR, 0);
				else if (ptr->sep == RGT)
					redirect_fd(ptr->next->av[0],
								O_RDWR | O_CREAT | O_TRUNC,
								1);
				else if (ptr->sep == DRGT)
					redirect_fd(ptr->next->av[0],
								O_RDWR | O_CREAT | O_APPEND,
								1);
			}
		}
		else
			return (0);
		ptr = ptr->next;
	}
	return (0);
}

int			red_pipe(t_tfrk *lst)
{
	if (lst->prev != NULL)
	{
		if ((dup2(lst->prev->pfd[0], 0)) == -1)
			return (-1);
		close(lst->prev->pfd[0]);
	}
	if (lst->pfd[1] != 0)
	{
		if ((dup2(lst->pfd[1], 1)) == -1)
			return (-1);
	}
	if (lst->pfd[0] != 0)
		close(lst->pfd[0]);
	if (lst->pfd[1] != 0)
		close(lst->pfd[1]);
	return (0);
}
