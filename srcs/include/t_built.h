/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_built.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 03:24:48 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 14:45:33 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_BUILT_H
# define T_BUILT_H

typedef	struct			s_built
{
	int					(*f)(int, char **);
	char				*name;
	struct s_built		*next;
}						t_built;

#endif
