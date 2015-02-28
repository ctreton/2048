/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:02:12 by ctreton           #+#    #+#             */
/*   Updated: 2013/11/30 03:18:42 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*des;
	const char	*src;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	src = s2;
	des = s1;
	while (i < n)
	{
		*des = *src;
		if (*src == c)
		{
			des++;
			return (des);
		}
		des++;
		src++;
		i++;
	}
	return (NULL);
}
