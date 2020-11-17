/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 15:39:10 by user42            #+#    #+#             */
/*   Updated: 2020/11/17 17:57:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minishell.h"
#include "../include/env.h"

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
	if (!(var = get_var(g_all.var, tmp)))
		return (NULL);
	if (len)
		*len += ft_strlen(var->content);
	free(tmp);
	return (var);
}

int		need_pipe(t_cmd *cmd)
{
	int sep;

	sep = 0;
	while (cmd != NULL)
	{
		sep = cmd->sep;
		if (sep == LFT || sep ==  RGT || sep == DRGT)
			cmd = cmd->next;
		else if (sep == PIPE)
			return (1);
		else if (sep == SEMI || sep == EOF)
			return (0);
	}
	return (0);
}
