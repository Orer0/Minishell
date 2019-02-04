/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:23:58 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/15 23:36:37 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			nb_dir(char *pwd)
{
	int		i;
	int		nb_dir;

	i = 0;
	nb_dir = 0;
	while (pwd[i] != '\0')
	{
		if (pwd[i] == '/' && pwd[i + 1] != '\0')
			nb_dir++;
		i++;
	}
	return (nb_dir);
}

char		*new_arg(char *pwd)
{
	int		nb_word;
	int		i;
	char	*copy;
	int		nb_sl;

	nb_sl = 0;
	copy = NULL;
	i = 0;
	nb_word = (nb_dir(pwd) - 1);
	if (nb_word <= 0)
		return (ft_strdup("/"));
	while (pwd[i] != '\0')
	{
		if (pwd[i] == '/')
			nb_sl++;
		if (nb_sl > nb_word)
			break ;
		i++;
	}
	copy = ft_strsub(pwd, 0, i);
	return (copy);
}
