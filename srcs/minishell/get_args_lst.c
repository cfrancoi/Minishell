/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:48:24 by user42            #+#    #+#             */
/*   Updated: 2020/11/20 15:58:34 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		is_char_var(char c)
{
	return (ft_isalnum(c) || c == '_');
}
int				get_final_len(char *ptr)
{
	int		i;
	char	qte;
	int		len;
	t_var	*var;

	qte = 0;
	i = 0;
	len = 0;
	while (ptr[i] && !(ptr[i] == ' ' && qte == 0))
	{
		if (ptr[i] == '"'|| (ptr[i] == '\'' && (qte == 0 || qte == ptr[i])))
			qte = (qte == ptr[i]) ? 0 : ptr[i];
		else if (ptr[i] == '$' && qte != '\'' && is_char_var(ptr[i + 1]))
		{
			if (!(var = variable(ptr, &i, &len)))
				return (-1);
		}
		else
			len++;
		i++;
	}
	return (len);
}

static char		*get_final_arg(char *ptr, int len, int qte)
{
	int		i;
	t_var	*var;
	char	*new;

	i = 0;
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new[len] = '\0';
	len = 0;
	while (ptr[i]  && !(ptr[i] == ' ' && qte == 0 ) )
	{
		if (ptr[i] == '"'|| (ptr[i] == '\'' && (qte == 0 || qte == ptr[i])))
			qte = (qte == ptr[i]) ? 0 : ptr[i];
		else if (ptr[i] == '$' && qte != '\'' && is_char_var(ptr[i + 1]))
		{
			if (!(var = variable(ptr, &i, NULL)))
				return (NULL);
			ft_memcpy(&new[len], var->content, ft_strlen(var->content));
			len += ft_strlen(var->content);
		}
		else
			new[len++] = ptr[i];
		i++;
	}		
	return (new);
}

void			get_args_lst(t_arg *lst)
{
	//
	int i = 1;
	//
	int len;

	while (lst)
	{
		len = get_final_len(lst->ptr);
		lst->ptr = get_final_arg(lst->ptr, len, 0);
		//
		++i;
		//
		lst = lst->next;
	}
}
