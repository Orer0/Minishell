/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 23:12:30 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/15 23:55:47 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		check_type(char *new, int *cap, char *arg)
{
	struct stat	buf;

	if (stat(new, &buf) == 0)
	{
		if (!(S_ISDIR(buf.st_mode)))
		{
			*cap = 1;
			error_cd(1, arg);
		}
	}
	else if (ft_strcmp("/", new) != 0)
	{
		error_cd(2, arg);
		*cap = 1;
	}
}

char		*sup_ret(char *new, t_list *envl)
{
	char	*copy;

	copy = NULL;
	if (new == NULL)
		return (new_arg(ret_pwd(envl)));
	else
	{
		copy = new_arg(new);
		ft_strdel(&new);
	}
	return (copy);
}

char		*add_dir(char *new, char *part, t_list *envl)
{
	if (new == NULL)
	{
		if (!(new = ft_strjoin_add(ret_pwd(envl), part, '/')))
			error_malloc();
	}
	else
	{
		if (ft_strcmp(new, "/") != 0)
			new = ft_strjoin_add_free(new, part, '/');
		else
			new = ft_strjoin_free_s1(&new, &part);
		if (new == NULL)
			error_malloc();
	}
	return (new);
}

char		*make_new_arg(char **part, t_list *envl, int *cap, char *arg)
{
	int		i;
	char	*new;

	new = NULL;
	i = -1;
	while (part[++i] != NULL)
	{
		if (ft_strcmp(".", part[i]) == 0)
			continue ;
		else if (ft_strcmp("..", part[i]) == 0)
			new = sup_ret(new, envl);
		else
			new = add_dir(new, part[i], envl);
		check_type(new, cap, arg);
	}
	return (new);
}
