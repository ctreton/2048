/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 06:17:44 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/25 17:07:21 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*res;
	int			i;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = ft_strnew(ft_strlen(s));
	if (res)
	{
		while (s[i] != '\0')
		{
			res[i] = f(i, s[i]);
			i++;
		}
	}
	return (res);
}
