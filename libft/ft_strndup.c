/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 19:53:00 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/24 20:20:10 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;

	str = (char*)malloc(sizeof(*str) * (ft_strlen(s1) + 1));
	if (str)
	{
		i = 0;
		while (s1[i] && i < n)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
