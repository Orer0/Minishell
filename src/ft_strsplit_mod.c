/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_mod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroblin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 17:32:25 by aroblin           #+#    #+#             */
/*   Updated: 2018/12/17 17:52:29 by aroblin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_ok(char c, char sep)
{
	if (c != sep && c != '\0' && c != '\t')
		return (1);
	return (0);
}

int			ft_count(char *str, char sep)
{
	if (*str == '\0')
		return (0);
	else if (ft_ok(*str, sep) && !ft_ok(*(str + 1), sep))
		return (1 + ft_count(str + 1, sep));
	return (0 + ft_count(str + 1, sep));
}

char		**ft_strsplit_mod(char *s, char c)
{
	char	**dest;
	size_t	len;
	int		i;
	int		x;

	i = 0;
	len = ft_count(s, c);
	if (!(dest = (char **)malloc(sizeof(char *) * (len + 1))) || !(s))
		return (NULL);
	len = 0;
	while (s[i] == c || s[i] == '\t')
		++i;
	while (s[i] != '\0')
	{
		x = i;
		while ((s[i] != c && s[i] != '\t') && s[i] != '\0')
			++i;
		dest[len] = ft_strsub(s, x, (i - x));
		++len;
		while (s[i] == c || s[i] == '\t')
			++i;
	}
	dest[len] = NULL;
	return (dest);
}
