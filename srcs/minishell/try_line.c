#include "../include/minishell.h"
#include "../include/env.h"
#include <string.h>
#include <unistd.h>
#include <stdio.h>

static	int		get_args(char *ptr, unsigned int *start)
{
	int	i;
	int len;
	int	under;

	i = 0;
	len = 0;
	under = 0;
	*start = (ptr[0] == '\"' || ptr[0] == '\'') ? 1 : 0;
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

static	char	*get_args2(char *ptr, int len)
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


static	void	print_args(t_args *lst)
{
	int i = 1;
	int len;
	while (lst)
	{
		len = get_args(lst->ptr, &lst->start);
		lst->ptr = get_args2(lst->ptr, len);
		printf("el %i: |%s|\n", i, lst->ptr);
		++i;
		lst = lst->next;
	}
}

static	void	add_args(t_args **lst, char *ptr)
{
	t_args	*new;
	t_args  *tmp;

	new = malloc(sizeof(t_args));
	new->next = NULL;
	new->ptr = ptr;
	new->quote = ptr[0];
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
}

static int count_args(char *ptr, t_args **lst)
{
	int ret;
	int i;
	int under;

	i = 0;
	under = 0;
	ret = (ptr[i] != '\0') ? 1 : 0;
	add_args(lst, &ptr[i]);
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
		{
			add_args(lst, &ptr[i + 1]);
			printf("[%s]\n", &ptr[i + 1]);
			ret++;
		}
		i++;
	}
	if (under != 0)
		return (-1);
	return (ret);
}

static char	**lst_to_array(t_args *lst)
{
	t_args	*tmp;
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
			lst = lst->next;
		}
		ptr[i] = NULL;

	}
	return (ptr);
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
	while (ptr[i])
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
	while (ptr[i])
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


char	**lst_args(char *line)
{
	t_args *lst = NULL;

	

	printf("\n|********************|\n");

	int i = count_args(line, &lst);
	if (i == -1)
	{
		printf("ERROR\nquote not close !\n");
		return(NULL);
	}
	printf("argc = %i\n", i);

	printf("|********************|\n");


	printf("|********************|\n");
	print_args(lst);

	char **av = lst_to_array(lst);
	printf("|********************|\n");

	i = 0;
	int len =0;
	while(av[i] != NULL)
	{
		len = get_final_len(av[i]);
		av[i] = get_final_arg(av[i], len);
		printf("av[%i] len = %i = |%s|\n", i, len ,av[i]);
		i++;
	}
	
	return (av);
}
