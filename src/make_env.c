/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:10:27 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/18 04:07:03 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_env(char **env, t_list **envl)
{
	char		buf_pwd[PATH_MAX];

	if (env[0] == NULL)
		create_var(envl, "PWD", getcwd(buf_pwd, PATH_MAX));
	else
		tab_to_list(env, envl);
	if (detec_cle(*envl, "PWD") == 0)
		create_var(envl, "PWD", getcwd(buf_pwd, PATH_MAX));
	if (detec_cle(*envl, "PATH") == 0)
		create_var(envl, "PATH", "/usr/bin:/bin:/usr/sbin:/sbin");
}

void	make_list(t_d_env *d_env, t_list **envl)
{
	t_list *tmp;

	if (!(tmp = ft_lstnew(d_env, sizeof(*d_env))))
		return ;
	ft_lst_add_end(envl, tmp);
	ft_memdel((void **)&d_env);
}

void	tab_to_list(char **env, t_list **envl)
{
	int		j;
	t_d_env	*d_env;
	char	*oldpwd;

	oldpwd = NULL;
	j = 0;
	while (env[j] != NULL)
	{
		if (!(d_env = (t_d_env *)ft_memalloc(sizeof(t_d_env))))
			return ;
		if (!(oldpwd = ft_strdup_to(env[j], '=')))
			return ;
		if (ft_strcmp("OLDPWD", oldpwd) == 0)
		{
			ft_strdel(&oldpwd);
			j++;
		}
		ft_strdel(&oldpwd);
		if (!(d_env->cle = ft_strdup_to(env[j], '=')))
			return ;
		if (!(d_env->value = ft_strdup_of(env[j], '=')))
			return ;
		make_list(d_env, envl);
		j++;
	}
}

char	**list_to_tab(t_list *list)
{
	char	**dest;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = list;
	if (!(dest = (char **)ft_memalloc(sizeof(char *) * (ft_lstlen(list) + 1))))
		return (NULL);
	while (tmp != NULL)
	{
		if (((t_d_env *)(tmp->content))->cle != NULL
			&& ((t_d_env *)(tmp->content))->value != NULL)
			dest[i] = ft_strjoin_add(((t_d_env *)(tmp->content))->cle,
					((t_d_env *)(tmp->content))->value, '=');
		else
			dest[i] = ft_strjoin(((t_d_env *)(tmp->content))->cle, "=");
		if (dest[i] == NULL)
			error_malloc();
		i++;
		tmp = tmp->next;
	}
	dest[i] = NULL;
	return (dest);
}
