/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 00:05:06 by ctreton           #+#    #+#             */
/*   Updated: 2013/11/25 04:21:18 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *)s;
	while (*res != '\0')
	{
		if (*res == c)
			return (res);
		res++;
	}
	if (*res == c)
		return (res);
	return (NULL);
}
