/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:48:55 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 04:59:58 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		add_var(t_list **envl_cop, char *str)
{
	char	**arg;

	arg = ft_strsplit(str, '=');
	if (detec_cle(*envl_cop, arg[0]) > 0)
		change_value(*envl_cop, arg[0], arg[1]);
	else
		create_var(envl_cop, arg[0], arg[1]);
	tab_del(arg);
}

void		error_env(char *str)
{
	ft_putstr("env: ");
	ft_putstr(str);
	ft_putendl(": No such file or directory");
}

void		manag_arg(char **tab, t_list **envl_cop, int i)
{
	char			**arg;
	char			*cop;

	cop = NULL;
	arg = NULL;
	arg = list_to_tab(*envl_cop);
	if (*envl_cop == NULL || detec_cle(*envl_cop, "PATH") == 0)
		make_path(envl_cop);
	if (detec_slh(tab[i]) == 1)
	{
		if (exe_root(tab[i], tab + i, arg) < 0)
			bad_command_env(tab[i]);
	}
	else if (go_exe(tab[i], tab + i, envl_cop, arg) < 0)
		bad_command_env(tab[i]);
	tab_del(arg);
}

int			way_arg(char **tab, t_list **envl_cop, char *opt, int i)
{
	if (ft_strfind(tab[i], '='))
		add_var(envl_cop, tab[i]);
	else
	{
		ft_strdel(&opt);
		manag_arg(tab, envl_cop, i);
		ft_lstdel(envl_cop, del);
		return (-1);
	}
	return (0);
}

void		ft_pars_env(char **tab, t_list **envl)
{
	int		i;
	t_list	*envl_cop;
	char	*opt;

	opt = NULL;
	i = option(tab, &opt);
	envl_cop = NULL;
	if (check_bad_option(opt, 'i') < 0)
	{
		usage_env();
		return ;
	}
	if (check_option(opt, 'i') != 1)
		ft_copy_list(*envl, &envl_cop);
	while (tab[i] != NULL)
	{
		if (way_arg(tab, &envl_cop, opt, i) < 0)
			return ;
		i++;
	}
	print_env(envl_cop);
	ft_strdel(&opt);
	ft_lstdel(&envl_cop, del);
}
