/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:02:05 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/15 23:55:43 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		final_change(char *new, t_list *envl, char *arg, char **part)
{
	if (new == NULL && ft_strcmp(part[0], ".") == 0)
		new = ret_pwd(envl);
	if (chdir(new) >= 0)
		change_value(envl, "PWD", new);
	else
		error_cd(3, arg);
}

void		change_path_link(t_list *envl, char *arg, char *buf_pwd)
{
	struct stat		buf_link;
	char			*link;
	char			*new;
	char			**part;
	int				cap;

	cap = 0;
	new = NULL;
	link = NULL;
	if (lstat(ret_pwd(envl), &buf_link) == 0)
		manag_var(envl, buf_pwd, buf_link);
	if (!(part = ft_strsplit(arg, '/')))
		error_malloc();
	if (arg[0] == '/')
		new = root_dir(arg, envl, part, &cap);
	else
		new = make_new_arg(part, envl, &cap, arg);
	if (cap == 0)
		final_change(new, envl, arg, part);
	tab_del(part);
	ft_strdel(&new);
	ft_strdel(&link);
}

void		change_path(t_list *envl, char *arg, char *buf_pwd)
{
	int		cap;

	cap = 0;
	if (detec_cle(envl, "OLDPWD") != 1)
		create_var(&envl, "OLDPWD", getcwd(buf_pwd, PATH_MAX));
	else
		change_value(envl, "OLDPWD", getcwd(buf_pwd, PATH_MAX));
	check_type(arg, &cap, arg);
	if (chdir(arg) < 0 && cap == 0)
		error_cd(3, arg);
	change_value(envl, "PWD", getcwd(buf_pwd, PATH_MAX));
}
