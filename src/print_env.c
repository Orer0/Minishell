/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:48:36 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/16 19:54:38 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_list *envl)
{
	t_list	*tmp;

	tmp = envl;
	while (tmp != NULL)
	{
		ft_putstr(((t_d_env *)(tmp->content))->cle);
		ft_putchar('=');
		if (((t_d_env *)(tmp->content))->value != NULL)
			ft_putendl(((t_d_env *)(tmp->content))->value);
		else
			ft_putchar('\n');
		tmp = tmp->next;
	}
}
