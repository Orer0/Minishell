/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:51:35 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/16 17:58:40 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_setenv(t_list *envl, char *cle, char *value)
{
	if (detec_cle(envl, cle) > 0)
	{
		if (ft_strcmp(detec_value(envl, cle), value) == 0)
			return (0);
		else
			change_value(envl, cle, value);
	}
	else
		create_var(&envl, cle, value);
	return (1);
}

void		value_add(char *arg, t_list *envl)
{
	char	**var_env;
	char	*value;
	int		j;

	j = 1;
	value = NULL;
	if (!(var_env = ft_strsplit(arg, '=')))
		error_malloc();
	while (var_env[j] != NULL)
	{
		if (value == NULL)
			value = ft_strdup(var_env[j]);
		else
			value = ft_strjoin_add(value, var_env[j], '=');
		if (value == NULL)
			error_malloc();
		j++;
	}
	ft_setenv(envl, var_env[0], value);
	tab_del(var_env);
	ft_strdel(&value);
}

void		exe_setenv(char **tab, t_list **envl)
{
	int		i;

	i = 1;
	while (tab[i] != NULL)
	{
		if (ft_strfind(tab[i], '=') && (ft_strlen_to(tab[i], '=') > 0))
			value_add(tab[i], *envl);
		else
		{
			ft_putendl("usage : setenv [name=value ...]");
			break ;
		}
		i++;
	}
	if (tab[1] == NULL)
		print_env(*envl);
}
