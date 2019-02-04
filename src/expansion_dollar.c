/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:26:57 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/16 22:13:00 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*isol_arg(char *arg, int k)
{
	char	*copy;
	int		t;
	int		len;

	len = 0;
	t = 0;
	copy = NULL;
	if (ft_strlen_to((arg + k), '$'))
	{
		len = ft_strlen_to((arg + k), '$');
		if (!(copy = (char *)ft_memalloc(sizeof(len + 1))))
			error_malloc();
	}
	else
	{
		if (!(copy = (char *)ft_memalloc(sizeof(ft_strlen(arg + k) + 1))))
			error_malloc();
	}
	while (arg[k] != '$' && arg[k] != '\0')
	{
		copy[t] = arg[k];
		t++;
		k++;
	}
	return (copy);
}

char		*replace_var(char *arg, int k, t_list *envl, char *var)
{
	char	*copy;
	char	*cpy;

	cpy = NULL;
	copy = isol_arg(arg, k);
	if (detec_value(envl, copy) != NULL)
	{
		cpy = detec_value(envl, copy);
		if (var == NULL)
			var = ft_strdup(cpy);
		else
			var = ft_strjoin_free_s1(&var, &cpy);
		if (var == NULL)
			error_malloc();
	}
	else
	{
		if (!(var = ft_strdup(" ")))
			error_malloc();
	}
	ft_strdel(&copy);
	return (var);
}

char		*check_arg(char *arg, t_list *envl)
{
	int		k;
	char	*var;

	var = NULL;
	k = 0;
	while (arg[k] != '\0')
	{
		if (arg[k] == '$')
		{
			k++;
			var = replace_var(arg, k, envl, var);
		}
		k++;
	}
	return (var);
}

char		**expansion_dollar(char **tab, t_list *envl)
{
	int		i;
	char	*var;
	int		t;

	i = 0;
	var = NULL;
	t = 0;
	while (tab[i] != NULL)
	{
		if (ft_strcmp(tab[i], "$") != 0)
			var = check_arg(tab[i], envl);
		if (var != NULL)
		{
			ft_strdel(&tab[i]);
			if (!(tab[i] = ft_strdup(var)))
				error_malloc();
			ft_strdel(&var);
		}
		i++;
	}
	ft_strdel(&var);
	return (tab);
}
