/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:57:37 by user42            #+#    #+#             */
/*   Updated: 2020/12/08 15:54:34 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include <string.h>


typedef struct		s_var
{
	char			*name;
	char			*content;
	int				protect;
	struct s_var	*next;
}					t_var;

# include "../libft/libft.h"

int		add_var(t_var **lst, t_var *to_add);
t_var	*get_var(t_var *lst, char *name);
char	*get_str_var(char *ptr);
int		print_var(t_var *ptr);
int		ls_var(t_var **lst, int protect);
t_var	*create_var(char *name, char *content, int protect);
void	cat_var(t_var *lst);
void	free_lst_var(t_var *lst);
t_var	*get_envp(char **envp);
int		edit_qmrk(int excode);
char	**lst_to_envp(t_var *lst);
int		is_protect(char *name);

#endif
