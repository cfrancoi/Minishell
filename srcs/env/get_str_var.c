/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:30:18 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/12/11 13:20:46 by cfrancoi         ###   ########lyon.fr   */
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
	while (ptr[i] && (ft_isalnum(ptr[i]) || ptr[i] == '_'))
		i++;
	var = ft_substr(ptr, 0, i);
	return (var);
}
