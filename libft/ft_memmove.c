/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:35:30 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/25 17:06:01 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	char			*b;
	char			*a;
	const char		*c;
	size_t			i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	a = (char *)malloc(sizeof(*a) * n);
	c = s2;
	b = s1;
	while (i < n)
	{
		a[i] = c[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (b);
}
