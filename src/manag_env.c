/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manag_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:41:04 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/16 19:54:07 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*detec_value(t_list *envl, char *cle)
{
	t_list	*tmp;

	tmp = envl;
	while (tmp != NULL)
	{
		if (ft_strcmp(cle, ((t_d_env *)(tmp->content))->cle) == 0)
			return (((t_d_env *)(tmp->content))->value);
		tmp = tmp->next;
	}
	return (NULL);
}

int		detec_cle(t_list *envl, char *cle)
{
	t_list	*tmp;

	if (envl == NULL)
		return (0);
	tmp = envl;
	while (tmp != NULL)
	{
		if (ft_strcmp(cle, ((t_d_env *)(tmp->content))->cle) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	change_value(t_list *envl, char *cle, char *new)
{
	t_list	*tmp;

	tmp = envl;
	while (tmp != NULL)
	{
		if (ft_strcmp(cle, ((t_d_env *)(tmp->content))->cle) == 0)
		{
			ft_strdel(&((t_d_env *)(tmp->content))->value);
			if (new != NULL)
			{
				if (!(((t_d_env *)(tmp->content))->value = ft_strdup(new)))
					error_malloc();
			}
			else
				((t_d_env *)(tmp->content))->value = NULL;
		}
		tmp = tmp->next;
	}
}

void	create_var(t_list **envl, char *cle, char *value)
{
	t_list	*tmp;
	t_d_env	*d_env;

	tmp = NULL;
	if (!(d_env = (t_d_env *)ft_memalloc(sizeof(t_d_env))))
		error_malloc();
	if (!(d_env->cle = ft_strdup(cle)))
		error_malloc();
	if (value != NULL)
	{
		if (!(d_env->value = ft_strdup(value)))
			error_malloc();
	}
	if (!(tmp = ft_lstnew(d_env, sizeof(*d_env))))
		error_malloc();
	ft_lst_add_end(envl, tmp);
	ft_memdel((void **)&d_env);
}
