/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 03:58:06 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 03:58:48 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		begin_by(char *command)
{
	if (command[0] == '.' && command[1] == '/')
		return (1);
	else if (command[0] == '/')
		return (1);
	else
		return (0);
}

int		detec_slh(char *cmd)
{
	int		i;
	int		sl;
	int		ot;

	sl = 0;
	ot = 0;
	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '/' || cmd[i] == '.')
			sl++;
		if (cmd[i] != '.' && cmd[i] != '/')
		{
			ot = i;
			break ;
		}
		i++;
	}
	if (sl <= ot || sl == (int)ft_strlen(cmd))
		return (sl);
	return (0);
}
