/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:52:03 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/10/26 18:17:26 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/env.h"
#include "../../Lib/libft.h"



char	*get_str_var(char *ptr)
{
	int		i;
	char	*var;

	i = 0;
	var = NULL;
	if (ptr[i] == '$')
		ptr++;
	else
		return (NULL);
	while(ptr[i] && ft_isalnum(ptr[i]))
		i++;
	var = ft_substr(ptr, 0, i);
	return (var);
}
