/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:23:43 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/17 18:06:11 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_copy_list(t_list *src, t_list **dest)
{
	t_list	*tmp;

	tmp = src;
	while (tmp != NULL)
	{
		create_var(dest, ((t_d_env *)(tmp->content))->cle,
				((t_d_env *)(tmp->content))->value);
		tmp = tmp->next;
	}
}
