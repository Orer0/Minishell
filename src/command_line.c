/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:43:47 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 05:00:20 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*set_bt(char *command)
{
	if (ft_strcmp("echo", command) == 0)
		return (&echo);
	else if (ft_strcmp("exit", command) == 0)
		return (&bt_exit);
	else if (ft_strcmp("cd", command) == 0)
		return (&ft_cd);
	else if (ft_strcmp("env", command) == 0)
		return (&ft_pars_env);
	else if (ft_strcmp("setenv", command) == 0)
		return (&exe_setenv);
	else if (ft_strcmp("unsetenv", command) == 0)
		return (&exe_unsetenv);
	return (NULL);
}

int		exe_root(char *cmd, char **tab, char **env)
{
	struct stat		buf;

	stat(cmd, &buf);
	if (access(cmd, X_OK) == 0 && S_ISREG(buf.st_mode))
	{
		exe_command(tab, env, cmd);
		return (1);
	}
	return (-1);
}

int		go_exe(char *cmd, char **tab, t_list **envl, char **env)
{
	char			*copy_command;

	if (check_command(cmd, envl, &copy_command) == 1)
	{
		if (env[0] == NULL)
			env = list_to_tab(*envl);
		exe_command(tab, env, copy_command);
		ft_strdel(&copy_command);
		return (1);
	}
	return (-1);
}

void	manag_command(char *command, char **env, t_list **envl, char **tab)
{
	void			(*fonct)(char **tab, t_list **envl);

	fonct = set_bt(command);
	env = list_to_tab(*envl);
	if (fonct != NULL)
		fonct(tab, envl);
	else if (command != NULL)
	{
		if (detec_slh(command) > 0)
		{
			if (exe_root(command, tab, env) < 0)
				bad_command(command);
		}
		else if (go_exe(command, tab, envl, env) < 0)
			bad_command(command);
	}
	tab_del(env);
}

void	command_line(char **env, t_list **envl)
{
	char	**tab;
	char	*line;
	int		i;

	i = 0;
	tab = NULL;
	line = NULL;
	if (read_prompt(0, &line) > 0)
	{
		if (!(tab = ft_strsplit_mod(line, ' ')))
			error_malloc();
		if (ft_strfind(line, '$') == 1)
			tab = expansion_dollar(tab, *envl);
		if (ft_strfind(line, '~') == 1)
			tab = expansion_tilde(tab, *envl);
		manag_command(tab[0], env, envl, tab);
		ft_strdel(&line);
		tab_del(tab);
	}
	else
	{
		ft_strdel(&line);
		error_read();
	}
	ft_strdel(&line);
}
