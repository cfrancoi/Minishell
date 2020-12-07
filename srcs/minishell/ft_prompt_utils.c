/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:00:23 by user42            #+#    #+#             */
/*   Updated: 2020/12/07 16:19:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_path(void)
{
	char	*path;

	if (!(path = getcwd(NULL, 0)))
		return (-1);
	ft_putstr_fd("Minishell : ", 1);
	ft_putstr_fd(path, 1);
	ft_putstr_fd(" : ", 1);
	free(path);
	return (0);
}
