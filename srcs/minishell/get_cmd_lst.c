/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:10:23 by user42            #+#    #+#             */
/*   Updated: 2020/11/25 12:02:32 by cfrancoi         ###   ########lyon.fr   */
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
	{
		if (*(s + 1) && *(s + 1) == '>')
		{
			dst->sep = DRGT;
			*s = 0;
			s++;
		}
		else
			dst->sep = RGT;
	}
	*s = 0;
	if (!(dst->next = malloc(sizeof(t_cmd))))
		return (NULL);
	dst = dst->next;
	dst->sep = 0;
	dst->str = s + 1;
	*src = s;
	return (dst);
}

int		get_cmd_lst(char *s, t_cmd **dst)
{
	t_cmd	*first;
	int		i;

	if (!(*dst = malloc (sizeof(t_cmd))))
		return (-1);
	first = *dst;
	(*dst)->str = s;
	(*dst)->sep = 0;
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
	(*dst)->next = NULL;
	*dst = first;
	return (0);
}
