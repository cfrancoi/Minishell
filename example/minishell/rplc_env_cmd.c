/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rplc_env_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 16:09:57 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/10/26 16:56:47 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include "../include/env.h"
#include "../Lib/libft.h"
#include <stdio.h>


static char		*str_next_world(char *src, char c)
{
	char	under;
	int		len;

	len = 0;
	under = 0;
	while(src[len] && !((src[len] == c) && under == 0))
	{
		if (src[len] == '\'')
			under = (under == 0) ? src[len] : 0;
		len++;
	}
	char *new = ft_substr(src, 0, len);
	printf("new = [%s]\n", new);

	return (new);
}

static char		*get_end_var(char *ptr, char c)
{
	int i;

	i = 0;

	while (ptr[i] && (ptr[i] != c && ptr[i] != ' '))
		++i;
	return (&ptr[i]);
}
static char		*get_new(char *ptr, char *line, char c)
{
	char	*var;
	char	*new;
	char	*end;
	t_var	*env;
	
	var = ft_strccpy(&ptr[1], c); //a refaire
	str_next_world(ptr, c);
	new = ft_strccpy(line, '$'); // not good '$ can be use'
	//printf("%s\n", var);
	env = get_var(g_list, var);
	free(var);
	if (env != NULL)
		var = env->content;
	else
		var = NULL;

//	printf("%s %i\n", new, (int)ft_strlen(new));
//	printf("%s\n", var);
	
	if(var != NULL)
		new = ft_strjoinf(new, var, 1);
	end = get_end_var(ptr, c);
	if (*end != '\0')
		new = ft_strjoinf(new ,end, 1);
	free(line);
	//free(var);
	return (new);
}

char			*rplc_env_cmd(char *ptr)
{
	char	*new;
	int		i;
	int		under;

	new = ptr;
	under = 0;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == 39 || ptr[i] == '"')
		{
			if (under == 0)
				under = ptr[i];
			else if (under == ptr[i])
				under = 0;
		}

		if (ptr[i] == '$' && ptr[i + 1] != '\0' && under != 39)
		{
//			printf("ENTER\n");
			ptr = get_new(&ptr[i], ptr, (under == 0) ? ' ' : under);
			//free(ptr);
			i = 0;
		}
		else
			++i;
	}
	new = ptr;
	printf("%s\n", new);
	return (new);
}
