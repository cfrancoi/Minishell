/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_dup_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 15:37:21 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/06 16:30:37 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		redirect_fd(const char *path, int flags, int fd)
{
		int lfd;

		if ((lfd = open(path, flags, 0666)) == -1)
			return (-1);
		if ((dup2(lfd, fd)) == -1)
			return (-1);
		return (close(lfd));
}

int		msh_dup_fd(t_cmd *ptr)
{
	int ret;

	while (ptr)
	{
		if (ptr->sep == LFT | ptr->sep == RGT | ptr->sep == DRGT)
		{
			if (ptr->next)
			{
				if (ptr->sep == LFT)
					redirect_fd(ptr->next->av[0], (O_RDWR) , 0);
				else if (ptr->sep == RGT)
					redirect_fd(ptr->next->av[0], (O_RDWR | O_CREAT | O_TRUNC) , 1);
				else if (ptr->sep == DRGT)
					redirect_fd(ptr->next->av[0], (O_RDWR | O_CREAT | O_APPEND ) ,  1);
			}
		}
		else
			return (0);
		ptr = ptr->next;
	}
	return (0);
}
