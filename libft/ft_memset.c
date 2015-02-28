/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:40:16 by ctreton           #+#    #+#             */
/*   Updated: 2013/11/25 00:18:39 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*d;

	if (!b)
		return (NULL);
	i = 0;
	d = b;
	while (i < len)
	{
		*d = c;
		d++;
		i++;
	}
	return (b);
}
