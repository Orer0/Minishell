/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:59:23 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/17 13:52:44 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		exe_command(char **tab, char **env, char *command)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid == -1)
	{
		error_fork();
		return ;
	}
	else if (pid == 0)
	{
		if (execve(command, tab, env) < 0)
		{
			ft_putstr("minishell: ");
			ft_putstr(command);
			ft_putendl(": Permission denied");
			exit(0);
		}
	}
	else
		wait(&status);
}
