/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:58:32 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/13 15:59:40 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **tab, t_list **envl)
{
	int		i;

	(void)envl;
	i = 1;
	if (ft_strcmp(tab[1], "-n") == 0)
		i = 2;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		if (tab[i + 1] != NULL)
			ft_putchar(' ');
		i++;
	}
	if (ft_strcmp(tab[1], "-n") != 0)
		ft_putchar('\n');
}
