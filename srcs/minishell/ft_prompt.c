/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:01:14 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/13 17:14:05 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>

int		ft_prompt(t_built *built)
{
	int		ret;
	char	*line;
	t_cmd	*ptr;

	ret = 1;
	ptr = NULL;
	line = NULL;
	while (ret)
	{
		printf("Minishell : \n");
		ret = get_next_line(0, &line);
		ret = msh_parsing(line, &ptr);
		
		msh_push_cmd(&ptr, built);
		ptr = NULL;
		free(line);
	}
	return(ret);
}
