/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:20:31 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/17 14:22:59 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		usage_env(void)
{
	ft_putendl("env: illegal option");
	ft_putendl("usage: env [-i] [name=value ...] [utility [argument ...]]");
}

void		usage_cd(void)
{
	ft_putendl("cd: invalid option");
	ft_putendl("cd: usage: cd [-L|-P] [dir]");
}
