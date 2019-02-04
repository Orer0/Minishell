/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_way_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:16:08 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 05:01:59 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*bad_command_env(char *command)
{
	struct stat		buf;

	ft_bzero(&buf, sizeof(struct stat));
	if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
	{
		ft_putstr("env : ");
		ft_putstr(command);
		ft_putendl(": Permission denied");
		return (NULL);
	}
	else if (S_ISDIR(buf.st_mode))
	{
		ft_putstr("env : ");
		ft_putstr(command);
		ft_putendl(": is a directory");
		return (NULL);
	}
	else
	{
		ft_putstr("env: ");
		ft_putstr(command);
		ft_putendl(": command not found");
	}
	return (NULL);
}
