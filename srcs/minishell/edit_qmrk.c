/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_qmrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancoi <cfrancoi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:41:58 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 14:31:46 by cfrancoi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			edit_qmrk(int excode)
{
	free(g_all.var->content);
	if (!(g_all.var->content = ft_itoa_base(excode, "0123456789")))
		return (-1);
	return (excode);
}
