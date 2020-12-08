/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:52:03 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/08 01:40:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"



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
	if (ptr[i] == '?')
		return (ft_strdup("?"));
	while(ptr[i] && ft_isalnum(ptr[i]))
		i++;
	var = ft_substr(ptr, 0, i);
	return (var);
}
