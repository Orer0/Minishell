/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_path_root.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:20:55 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/15 23:12:21 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*sup_ret_root(char *new, t_list *envl)
{
	char	*copy;

	(void)envl;
	copy = NULL;
	if (new == NULL)
		return (new_arg("/"));
	else
	{
		copy = new_arg(new);
		ft_strdel(&new);
	}
	return (copy);
}

char		*add_dir_root(char *new, char *part)
{
	if (new == NULL)
	{
		if (!(new = ft_strjoin("/", part)))
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

char		*root_dir(char *arg, t_list *envl, char **part, int *cap)
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
			new = sup_ret_root(new, envl);
		else
			new = add_dir_root(new, part[i]);
		check_type(new, cap, arg);
	}
	if (new == NULL)
	{
		if (!(new = ft_strdup("/")))
			error_malloc();
	}
	return (new);
}
