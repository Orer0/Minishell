/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_change_directory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 23:26:01 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 04:01:06 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	home(t_list *envl, char *path, char *buf_pwd)
{
	if (detec_cle(envl, "HOME") != 1)
	{
		ft_putendl("minishell : cd: HOME not set");
		return ;
	}
	path = detec_value(envl, "HOME");
	change_value(envl, "PWD", detec_value(envl, "HOME"));
	if (detec_cle(envl, "OLDPWD") != 1)
		create_var(&envl, "OLDPWD", getcwd(buf_pwd, PATH_MAX));
	else
		change_value(envl, "OLDPWD", getcwd(buf_pwd, PATH_MAX));
	chdir(path);
}

void	type_link(char *path, t_list *envl, char *buf_pwd)
{
	struct stat		buf_link;

	if (lstat(path, &buf_link) == 0)
	{
		if (S_ISLNK(buf_link.st_mode))
			change_value(envl, "PWD", path);
		else
			change_value(envl, "PWD", getcwd(buf_pwd, PATH_MAX));
	}
}

void	oldpwd(t_list *envl, char *path, char *buf_pwd)
{
	struct stat		buf_link;

	if (detec_cle(envl, "OLDPWD") != 1)
	{
		ft_putendl("minishell : cd: OLDPWD not set");
		return ;
	}
	if (!(path = ft_strdup(detec_value(envl, "OLDPWD"))))
		error_malloc();
	if (lstat(ret_pwd(envl), &buf_link) == 0)
	{
		if (S_ISLNK(buf_link.st_mode))
			change_value(envl, "OLDPWD", detec_value(envl, "PWD"));
		else
			change_value(envl, "OLDPWD", getcwd(buf_pwd, PATH_MAX));
	}
	chdir(path);
	type_link(path, envl, buf_pwd);
	ft_strdel(&path);
}

void	opt_way(t_list *envl, char *arg, char *opt)
{
	char	buf_pwd[PATH_MAX];

	if (check_final_option(opt, 'P'))
		change_path(envl, arg, buf_pwd);
	else
		change_path_link(envl, arg, buf_pwd);
}

void	ft_cd(char **arg, t_list **envl)
{
	char	*path;
	char	buf_pwd[PATH_MAX];
	char	*opt;
	int		i;

	opt = NULL;
	i = option(arg, &opt);
	path = NULL;
	if (check_bad(opt, 'L', 'P') < 0)
	{
		usage_cd();
		return ;
	}
	if (arg[i] == NULL || (ft_strcmp("--", arg[i]) == 0
		&& ft_tab_strlen(arg + i) > 0))
		home(*envl, path, buf_pwd);
	else if (ft_strcmp("-", arg[i]) == 0)
		oldpwd(*envl, path, buf_pwd);
	else
		opt_way(*envl, arg[i], opt);
	ft_strdel(&opt);
}
