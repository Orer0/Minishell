/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:39:06 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/16 17:42:07 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ret_pwd(t_list *envl)
{
	char	buf_pwd[PATH_MAX];

	if (detec_value(envl, "PWD") != NULL)
		return (detec_value(envl, "PWD"));
	return (getcwd(buf_pwd, PATH_MAX));
}
