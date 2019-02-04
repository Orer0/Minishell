/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:59:10 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/15 21:59:35 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		error_cd(int err, char *arg)
{
	if (err == 1)
	{
		ft_putstr("minishell: cd: ");
		ft_putstr(arg);
		ft_putendl(": Not a directory");
	}
	else if (err == 2)
	{
		ft_putstr("cd : no such file or directory: ");
		ft_putendl(arg);
	}
	else if (err == 3)
	{
		ft_putstr("minishell: cd: ");
		ft_putstr(arg);
		ft_putendl(": Permission denied");
	}
}
