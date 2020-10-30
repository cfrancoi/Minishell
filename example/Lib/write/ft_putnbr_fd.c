/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 11:56:00 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/03/08 11:56:02 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	unsigned int	nb;
	char			c;

	if (i < 0)
	{
		write(fd, "-", 1);
		nb = (i * -1);
	}
	else
		nb = i;
	if (nb >= 10)
	{
		c = (nb % 10) + 48;
		nb = nb / 10;
		ft_putnbr_fd((int)nb, fd);
	}
	else if (nb < 10)
		c = nb + 48;
	write(fd, &c, 1);
}
