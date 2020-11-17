/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 13:52:44 by cfrancoi          #+#    #+#             */
/*   Updated: 2020/11/17 15:59:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include "../libft/libft.h"
# include <string.h>

typedef struct		s_var
{
	char			*name;
	char			*content;
	struct s_var	*next;
}					t_var;

int		g_qm;
t_var	*g_list;


int		add_var(t_var **lst, t_var *to_add);
t_var	*get_var(t_var *lst, char *name);
char	*get_str_var(char *ptr);
int		print_var(t_var *ptr);
int		ls_var(t_var **lst);
t_var	*create_var(char *name, char *content);
void	free_lst_var(t_var *lst);
int		get_envp(char **envp);
int		edit_qmrk(int excode, char *cmd);
char	**lst_to_envp(t_var *lst);

#endif
