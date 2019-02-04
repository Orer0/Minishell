/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:50:12 by aroblin           #+#    #+#             */
/*   Updated: 2019/01/10 13:46:37 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		new_lst(t_list **envl, t_list *tmp, t_list *prev, int i)
{
	t_list *temp;

	temp = tmp;
	if (i == 0)
		*envl = (*envl)->next;
	else
	{
		tmp = prev;
		tmp->next = tmp->next->next;
	}
	ft_lstdelone(&temp, del);
}

void		ft_unsetenv(t_list **envl, char *cle)
{
	t_list	*tmp;
	t_list	*prev;
	int		i;

	i = 0;
	tmp = *envl;
	prev = *envl;
	if (cle == NULL)
	{
		print_env(*envl);
		return ;
	}
	while (tmp != NULL)
	{
		if (ft_strcmp(cle, ((t_d_env *)(tmp->content))->cle) == 0)
		{
			new_lst(envl, tmp, prev, i);
			break ;
		}
		i++;
		prev = tmp;
		tmp = tmp->next;
	}
}

void		exe_unsetenv(char **tab, t_list **envl)
{
	int		i;

	i = 1;
	while (tab[i] != NULL)
	{
		if (detec_cle(*envl, tab[i]) > 0)
			ft_unsetenv(envl, tab[i]);
		i++;
	}
}
