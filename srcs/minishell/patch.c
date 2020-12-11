#include "minishell.h"

static char		**ft_arrayjoin(char **a1, char **a2)
{
	size_t	len;
	char	**new;
	int		j;
	int		i;

	len = ft_array_len(a1) + ft_array_len(a2);

	if ((new = malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	new[len] = NULL;
	j = 0;
	i = -1;
	while (a1[++i])
	{
		new[j] = ft_strdup(a1[i]);
		if (new[j++] == NULL)
			return (NULL);
	}
	i = -1;
	while (a2[++i])
	{
		new[j] = ft_strdup(a2[i]);
		if (new[j++] == NULL)
			return (NULL);
	}
	return (new);
}

static char		**add_av(t_cmd *ptr)
{
	char **av;
	char **tmp;
	
	av = ptr->av;
	while(ptr->sep == LFT || ptr->sep == RGT || ptr->sep == DRGT)
	{
		if (ptr->next->av[0] && ptr->next->av[1])
		{
			tmp = av;
			av = ft_arrayjoin(av, &ptr->next->av[1]);
			ft_array_free(tmp);
			if (av == NULL)
				return (NULL);
		}
		ptr = ptr->next;
	}
	return (av);
}


static	t_cmd		*get_next_cmd(t_cmd *ptr)
{
	while (ptr->sep == LFT || ptr->sep == RGT || ptr->sep == DRGT)
		ptr = ptr->next;
	return (ptr->next);
}

int			av_last_alloc(t_cmd *ptr)
{
	while (ptr)
	{
		if (ptr->sep == LFT || ptr->sep == RGT || ptr->sep == DRGT)
			if ((ptr->av = add_av(ptr)) == NULL)
				return (-1);
		ptr = get_next_cmd(ptr);
	}
	return (0);
}