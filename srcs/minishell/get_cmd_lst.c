/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:10:23 by user42            #+#    #+#             */
/*   Updated: 2020/12/11 16:15:56 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int		free_all(t_cmd *first)
{
	t_cmd	*tmp;

	while (first)
	{
		tmp = first->next;
		free(first);
		first = tmp;
	}
	return (-1);
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
				return (free_all(first));
		}
		s++;
	}
	*dst = first;
	return (0);
}
