/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_qmrk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:41:58 by user42            #+#    #+#             */
/*   Updated: 2020/12/08 20:33:43 by user42           ###   ########.fr       */
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
