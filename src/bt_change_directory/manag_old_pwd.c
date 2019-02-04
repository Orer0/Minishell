/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_old_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 23:11:00 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/15 23:20:51 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		manag_var(t_list *envl, char *buf_pwd, struct stat buf_link)
{
	if (detec_cle(envl, "OLDPWD") != 1)
		create_var(&envl, "OLDPWD", getcwd(buf_pwd, PATH_MAX));
	else
	{
		if (S_ISLNK(buf_link.st_mode))
			change_value(envl, "OLDPWD", detec_value(envl, "PWD"));
		else
			change_value(envl, "OLDPWD", getcwd(buf_pwd, PATH_MAX));
	}
}
