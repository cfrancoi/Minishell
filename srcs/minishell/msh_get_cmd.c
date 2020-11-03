/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:29:50 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/03 16:14:33 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

 /* Part 1 */
static void		*add_args(char *ptr, t_arg **lst)
{
	t_arg	*new;
	t_arg  *tmp;

	if ((new = malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	new->next = NULL;
	new->ptr = ptr;
	if (*lst == NULL)
	{
		*lst = new; 
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

static int		get_args_ptr(char *ptr, t_arg **lst)
{
	int i;
	int under;

	i = 0;
	under = 0;
	if (ptr[i] != ' ')
		if (add_args(&ptr[i], lst) == NULL)
			return (-1);
	while (ptr[i])
	{
		if (ptr[i] == '"' || ptr[i] == 39 )
		{
			if (under == 0)
				under = ptr[i];
			else if (ptr[i] == under)
				under = 0;
		}
		if (under == 0 && ptr[i] == ' ' && ptr[i + 1] != ' ' && ptr[i + 1])
			if (add_args(&ptr[i + 1], lst) == NULL)
				return (-1);
		i++;
	}
	if (under != 0)
		return (-1);
	return (1);
}
/* ***** */


/* Part 2 */

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

int		get_final_len(char *ptr)
{
	int		i;
	char	qte;
	int		len;
	char	*tmp;
	t_var	*var;

	qte = 0;
	i = 0;
	len = 0;
	while (ptr[i] && !(ptr[i] == ' ' && qte == 0))
	{
		if (ptr[i] == '"'|| ptr[i] == '\'')
			if (qte == 0)
				qte = ptr[i];
			else if (qte == ptr[i])
				qte = 0;
			else
				len++;
		else if (ptr[i] == '$' && qte != '\'' && ft_isalnum(ptr[i + 1]))
		{
			tmp = get_str_var(&ptr[i]);
			i += ft_strlen(tmp);
			var = get_var(g_list, tmp);
			len += ft_strlen(var->content);
			free(tmp);
		}
		else
			len++;
		i++;
	}
	return (len);
}

static	char	*get_final_arg(char *ptr, int len)
{
	int		i;
	char	qte;
	char	*tmp;
	t_var	*var;
	char	*new;

	qte = 0;
	i = 0;
	new = malloc(sizeof(char) * (len + 1));
	new[len] = '\0';
	len = 0;
	while (ptr[i]  && !(ptr[i] == ' ' && qte == 0 ) )
	{
		//printf("[%i][%i][%s]\n",i ,len, new);
		if (ptr[i] == '"'|| ptr[i] == '\'')
			if (qte == 0)
				qte = ptr[i];
			else if (qte == ptr[i])
				qte = 0;
			else
				new[len++] = ptr[i];
		else if (ptr[i] == '$' && qte != '\'' && ft_isalnum(ptr[i + 1]))
		{
			tmp = get_str_var(&ptr[i]);
			i += ft_strlen(tmp);
			var = get_var(g_list, tmp);
			ft_memcpy(&new[len], var->content, ft_strlen(var->content));
			len += ft_strlen(var->content);
			free(tmp);
		}
		else
			new[len++] = ptr[i];
		i++;
	}		
	return (new);
}

static	void	get_args_lst(t_arg *lst)
{
	int i = 1;
	int len;
	while (lst)
	{
		len = get_final_len(lst->ptr);
		lst->ptr = get_final_arg(lst->ptr, len);
		printf("el %i: |%s|\n", i, lst->ptr);
		++i;
		lst = lst->next;
	}
}


/* ***** */

/* Part 3 */

static char	**lst_to_array(t_arg *lst)
{
	t_arg	*tmp;
	int		i;
	char	**ptr;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}	
	if ((ptr = malloc(sizeof(char *) * (i + 1))))
	{
		i = 0;
		while(lst)
		{
			ptr[i++] = lst->ptr;
			tmp = lst->next;
			free(lst);
			lst = tmp;
		}
		ptr[i] = NULL;
	}
	return (ptr);
}

/* ***** */ 


char			**msh_get_cmd(char *ptr)
{
	t_arg	*lst;
	char	**av;
	
	lst = NULL;

	get_args_ptr(ptr, &lst);
	get_args_lst(lst); /* need to free /!\ */
	av = lst_to_array(lst);


	return (av);
}

/*
int main(int ac, char **av)
{
	char **lol = msh_get_cmd(av[1]);

	int i = 0;

	while(lol[i])
	{
		printf("av[%i] = %s\n", i, lol[i]);
		i++;
	}
}
*/
