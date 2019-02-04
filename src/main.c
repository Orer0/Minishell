/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 16:58:10 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/17 21:47:13 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	t_list	*envl;

	(void)ac;
	(void)av;
	envl = NULL;
	make_env(env, &envl);
	shell_level(&envl);
	while (1)
	{
		ft_putstr("$> ");
		command_line(env, &envl);
	}
	ft_lstdel(&envl, del);
	return (0);
}
