/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:39:10 by user42            #+#    #+#             */
/*   Updated: 2020/11/07 19:50:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minishell.h"

int		pass_quotes(char *str, int type)
{
	int r;

	r = 1;
	while (str[r] && str[r] != type)
		r++;
	return (r);
}

t_var	*variable(char *ptr, int *i, int *len)
{
	char	*tmp;
	t_var	*var;

	if (!(tmp = get_str_var(&ptr[*i])))
		return (NULL);
	*i += ft_strlen(tmp);
	if (!(var = get_var(g_list, tmp)))
		return (NULL);
	*len += ft_strlen(var->content);
	free(tmp);
	return (var);
}
