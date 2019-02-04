/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:03:28 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 01:39:48 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			make_path(t_list **envl)
{
	int		fd;
	char	*line;
	char	*path;

	(void)envl;
	path = NULL;
	if (!(fd = open("/etc/paths", O_RDONLY)))
		error_open();
	while (read_prompt(fd, &line) > 0)
	{
		if (path == NULL)
			path = ft_strdup(line);
		else
			path = ft_strjoin_add_free(path, line, ':');
		if (path == NULL)
			error_malloc();
		ft_strdel(&line);
	}
	create_var(envl, "PATH", path);
	ft_strdel(&line);
	ft_strdel(&path);
	close(fd);
	return (0);
}

char		*check_path(char **path, char *command)
{
	int				i;
	char			*cop_command;

	cop_command = NULL;
	i = 0;
	while (path[i] != NULL)
	{
		if (!(cop_command = ft_strjoin_add(path[i], command, '/')))
			error_malloc();
		if (access(cop_command, X_OK) == 0)
			return (cop_command);
		ft_strdel(&cop_command);
		i++;
	}
	return (NULL);
}
