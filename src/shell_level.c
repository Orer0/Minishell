/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:42:37 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/16 17:43:08 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_level(t_list **envl)
{
	int		shlvl;
	char	*shl;

	shl = NULL;
	shlvl = 0;
	if (detec_cle(*envl, "SHLVL"))
	{
		shlvl = ft_atoi(detec_value(*envl, "SHLVL"));
		shlvl++;
		shl = ft_itoa(shlvl);
		change_value(*envl, "SHLVL", shl);
		ft_strdel(&shl);
	}
	else
		create_var(envl, "SHLVL", "1");
}
