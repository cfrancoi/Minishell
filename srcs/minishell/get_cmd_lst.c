/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:10:23 by user42            #+#    #+#             */
/*   Updated: 2020/11/27 15:03:11 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_cmd	*edit_cmd(char **src, t_cmd *dst)
{
	char	*s;

	s = *src;
	if (*s == '|')
		dst->sep = PIPE;
	if (*s == '<')
		dst->sep = LFT;
	if (*s == ';')
		dst->sep = SEMI;
	if (*s == '>')
		dst->sep = RGT;
	if (*(s + 1) && *(s + 1) == '>' && *(s + 1) == '>')
	{
		dst->sep = DRGT;
		*s++ = 0;
	}
	*s = 0;
	if (!(dst->next = ft_calloc(sizeof(t_cmd), 1)))
		return (NULL);
	dst->next->str = s + 1;
	*src = s;
	return (dst->next);
}

int				get_cmd_lst(char *s, t_cmd **dst)
{
	t_cmd	*first;
	int		i;

	if (!(*dst = ft_calloc(sizeof(t_cmd), 1)))
		return (-1);
	first = *dst;
	(*dst)->str = s;
	while (*s)
	{
		if (*s == '|' || *s == '>' || *s == '<' || *s == ';')
		{
			if (!((*dst) = edit_cmd(&s, *dst)))
				return (-1);
		}
		else if (*s == '\'' || *s == '\"')
		{
			i = (pass_quotes(s, *s));
			s += i;
			if (!(*s))
				return (-1);
		}
		s++;
	}
	*dst = first;
	return (0);
}
