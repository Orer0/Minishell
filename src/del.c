/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:47:10 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 04:21:33 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del(void *content, size_t size)
{
	(void)size;
	ft_strdel(&((t_d_env *)(content))->cle);
	ft_strdel(&((t_d_env *)(content))->value);
	ft_memdel(&content);
}

void	tab_del(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
