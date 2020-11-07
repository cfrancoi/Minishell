/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 19:48:24 by user42            #+#    #+#             */
/*   Updated: 2020/11/07 19:52:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static	int		get_arg_len(char *ptr)
{
	int	i;
	int len;
	int	under;

	i = 0;
	len = 0;
	under = 0;
	while (under != -1 && ptr[i])
	{
			if (ptr[i] == '\'' || ptr[i] == '\"')
			{
				if (under == 0)
					under = ptr[i];
				else if (ptr[i] == under)
					under = 0;
			}
			if ((ptr[i] == ' ' && under == 0) == 1)
				under = -1;
			else
				len++;
		i++;
	}
	return (len);
}

static	char	*get_arg(char *ptr, int len)
{
	int		i;
	int		j;
	int		under;
	char	*arg;

	i = 0;
	j = 0;
	under = 0;
	arg = (char *)malloc(sizeof(char) * (len + 1));
	while (under != -1 && ptr[i])
	{
			if (ptr[i] == '\'' || ptr[i] == '\"')
			{
				if (under == 0)
					under = ptr[i];
				else if (ptr[i] == under)
					under = 0;
			}
			if ((ptr[i] == ' ' && under == 0) == 1)
				under = -1;
			else
				arg[j++] = ptr[i];
		i++;
	}
	arg[j] = '\0';
	return (arg);
}

int					get_final_len(char *ptr)
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
		if (ptr[i] == '"'|| ptr[i] == '\'' && (qte == 0 || qte == ptr[i]))
			qte = (qte == ptr[i]) ? 0 : ptr[i];
		else if (ptr[i] == '$' && qte != '\'' && ft_isalnum(ptr[i + 1]))
		{
			if (!(var = variable(ptr, &i, &len)))
				return (NULL);
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
		if (ptr[i] == '"'|| ptr[i] == '\'' && (qte == 0 || qte == ptr[i]))
			qte = (qte == ptr[i]) ? 0 : ptr[i];
		else if (ptr[i] == '"'|| ptr[i] == '\'')
			len++;
		else if (ptr[i] == '$' && qte != '\'' && ft_isalnum(ptr[i + 1]))
		{
			if (!(var = variable(ptr, &i, &len)))
				return (NULL);
			ft_memcpy(&new[len], var->content, ft_strlen(var->content));
		}
		else
			new[len++] = ptr[i];
		i++;
	}		
	return (new);
}

void			get_args_lst(t_arg *lst)
{
	int i = 1;
	int len;
	while (lst)
	{
		len = get_final_len(lst->ptr);
		lst->ptr = get_final_arg(lst->ptr, len, 0);
		printf("el %i: |%s|\n", i, lst->ptr);
		++i;
		lst = lst->next;
	}
}
