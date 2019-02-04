/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_tilde.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:27:56 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 00:50:29 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		read_passwd(t_list **passwd)
{
	int		fd;
	char	*line;
	char	**data;

	data = NULL;
	line = NULL;
	if (!(fd = open("/etc/passwd", O_RDONLY)))
		error_open();
	while (read_prompt(fd, &line) > 0)
	{
		if (line[0] != '#')
		{
			if (!(data = ft_strsplit(line, ':')))
				error_malloc();
			create_var(passwd, data[0], data[5]);
			tab_del(data);
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
}

char		*only_home(t_list *envl, char *arg, char *copy)
{
	char	*ret_end;
	char	*end;

	ret_end = NULL;
	end = NULL;
	if (ft_strcmp(detec_value(envl, "LOGNAME"), copy) == 0
				|| arg[1] == '\0')
	{
		if (!(arg = ft_strdup(detec_value(envl, "HOME"))))
			error_malloc();
		ft_strdel(&copy);
		return (arg);
	}
	else if (arg[1] == '/')
	{
		if (!(end = ft_strdup_of(arg, '/')))
			error_malloc();
		if (!(ret_end = ft_strjoin_add(detec_value(envl, "HOME"), end, '/')))
			error_malloc();
		ft_strdel(&copy);
		ft_strdel(&end);
		return (ret_end);
	}
	return (NULL);
}

char		*replace_home(char *arg, t_list *passwd, t_list *envl)
{
	char	*copy;
	char	*ret;

	ret = NULL;
	if (!(copy = ft_strdup(arg + 1)))
		error_malloc();
	if (detec_value(passwd, copy) != NULL)
	{
		if (!(arg = ft_strdup(detec_value(passwd, copy))))
			error_malloc();
	}
	else if (detec_cle(envl, "HOME") == 1)
	{
		ret = only_home(envl, arg, copy);
		if (ret != NULL)
			return (ret);
	}
	else
	{
		ft_strdel(&copy);
		return (NULL);
	}
	ft_strdel(&copy);
	return (arg);
}

char		**expansion_tilde(char **tab, t_list *envl)
{
	t_list	*passwd;
	int		i;
	char	*home;

	home = NULL;
	i = 0;
	passwd = NULL;
	read_passwd(&passwd);
	while (tab[i] != NULL)
	{
		if (tab[i][0] == '~')
		{
			home = replace_home(tab[i], passwd, envl);
			if (home != NULL)
			{
				ft_strdel(&tab[i]);
				if (!(tab[i] = ft_strdup(home)))
					error_malloc();
				ft_strdel(&home);
			}
		}
		i++;
	}
	ft_lstdel(&passwd, del);
	return (tab);
}
