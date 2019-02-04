/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:18:01 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 04:59:13 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*bad_command(char *command)
{
	struct stat buf;

	ft_bzero(&buf, sizeof(struct stat));
	stat(command, &buf);
	if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
	{
		ft_putstr("minishell : ");
		ft_putstr(command);
		ft_putendl(": Permission denied");
		return (NULL);
	}
	else if (S_ISDIR(buf.st_mode))
	{
		ft_putstr("minishell : ");
		ft_putstr(command);
		ft_putendl(": is a directory");
		return (NULL);
	}
	else
	{
		ft_putstr("minishell: ");
		ft_putstr(command);
		ft_putendl(": command not found");
	}
	return (NULL);
}

int			command_way(char *command, t_list *envl, char *copy, char **cop)
{
	char			**path;

	(void)copy;
	path = NULL;
	if (command == NULL || ft_strcmp(" ", command) == 0)
		return (0);
	if (detec_cle(envl, "PATH") == 1)
	{
		if (!(path = ft_strsplit(detec_value(envl, "PATH"), ':')))
			error_malloc();
	}
	if (path != NULL)
	{
		if ((*cop = check_path(path, command)) != NULL)
		{
			tab_del(path);
			return (1);
		}
		tab_del(path);
	}
	return (0);
}
