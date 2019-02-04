/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:14:39 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/16 17:57:38 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		char_isalnum(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void	bad_arg(char *str)
{
	ft_putendl("exit");
	ft_putstr("minishell: exit: ");
	ft_putstr(str);
	ft_putendl(": numeric argument required");
	exit(EXIT_FAILURE);
}

void	bt_exit(char **tab, t_list **envl)
{
	int		i;

	(void)envl;
	i = 0;
	if (ft_tab_strlen(tab) > 2)
	{
		ft_putendl("minishell: exit: too many arguments");
		return ;
	}
	else
		ft_lstdel(envl, del);
	if (tab[1] == NULL)
	{
		ft_putendl("exit");
		exit(EXIT_SUCCESS);
	}
	else if (char_isalnum(tab[1]) == 1)
		bad_arg(tab[1]);
	else
	{
		ft_putendl("exit");
		exit(ft_atoi(tab[1]));
	}
}
