/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commande.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:47:36 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/17 16:28:04 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_command(char *command, t_list **envl, char **cop_command)
{
	char		*copy;

	copy = NULL;
	if (envl == NULL)
		make_path(envl);
	if (command == NULL || ft_strcmp(" ", command) == 0)
		return (0);
	else if (command_way(command, *envl, copy, cop_command) == 1)
		return (1);
	return (0);
}
