/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 22:07:34 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/17 14:01:16 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_malloc(void)
{
	ft_putendl("Memory alloction failed - The program is stopped");
	exit(0);
}

int		error_open(void)
{
	ft_putendl("Open fail on the file '/etc/paths'");
	return (-1);
}

void	error_fork(void)
{
	ft_putendl("Fork failed - The program is stopped");
}

void	error_read(void)
{
	ft_putendl("Read failed - The program is stopped");
	exit(0);
}
