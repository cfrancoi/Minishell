/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prgm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:13:30 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/09 17:19:39 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>
#include <string.h>

int main()
{
	char buf [1024];

	bzero(buf, 1024);

	while (read(0, buf, 1024))
	{
		write(1, buf, strlen(buf));
		write(1, buf, strlen(buf));
	}
}
