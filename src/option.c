/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:54:43 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/17 14:20:09 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			option(char **arg, char **opt)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	if (ft_strcmp("--", arg[i]) == 0)
		return (2);
	while (arg[i] != NULL)
	{
		if (ft_strcmp("--", arg[i]) != 0
				&& arg[i][0] == '-' && arg[i][1] != '\0')
		{
			if (*opt == NULL)
				*opt = ft_strdup(arg[i]);
			else
				*opt = ft_strjoin(*opt, arg[i]);
			if (*opt == NULL)
				error_malloc();
		}
		else
			return (i);
		i++;
	}
	return (i);
}

int			check_option(char *option, char letter)
{
	int	i;

	i = 0;
	if (option == NULL)
		return (0);
	while (option[i] != '\0')
	{
		if (option[i] == letter)
			return (1);
		i++;
	}
	return (0);
}

int			check_final_option(char *option, char letter)
{
	int	i;

	i = 0;
	if (option == NULL)
		return (0);
	while (option[i] != '\0')
	{
		i++;
	}
	if (option[i - 1] == letter)
		return (1);
	return (0);
}

int			check_bad_option(char *option, char letter)
{
	int	i;

	i = 0;
	if (option == NULL)
		return (0);
	while (option[i] != '\0')
	{
		if (option[i] == '-')
		{
			i++;
			continue;
		}
		if (option[i] != letter)
			return (-1);
		i++;
	}
	return (0);
}

int			check_bad(char *option, char letter, char let)
{
	int	i;

	i = 0;
	if (option == NULL)
		return (0);
	while (option[i] != '\0')
	{
		if (option[i] == '-')
		{
			i++;
			continue;
		}
		if (option[i] != letter && option[i] != let)
			return (-1);
		i++;
	}
	return (0);
}
