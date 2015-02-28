/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:52:38 by ctreton           #+#    #+#             */
/*   Updated: 2013/12/01 18:53:05 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = (char *)s;
	while (n > 0 && *tmp != '\0')
	{
		if (*tmp == c)
			return (tmp);
		tmp++;
		n--;
	}
	return (NULL);
}
