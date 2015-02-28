/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 03:00:59 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/25 17:07:57 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static char		**ft_crtab(char const *s)
{
	char	**tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(ft_strlen(s) + 1);
	if (tab)
		tab[i] = (!tab ? NULL : (char *)malloc(ft_strlen(s) + 1));
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	tab = ft_crtab(s);
	while (tab && tab[i] && s[k] != '\0')
	{
		if (c && s[k] != c && s[k] != '\0')
		{
			j = k;
			while (s[j] != c && s[j] != '\0')
				j++;
			tab[i] = ft_strsub(s, k, (j - k));
			i++;
			k = j - 1;
		}
		k++;
	}
	if (tab)
		tab[i] = (!tab ? NULL : '\0');
	return (tab);
}
