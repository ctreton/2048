/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 22:34:12 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/09 20:01:18 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	srclen;
	size_t	destlen;
	size_t	res;
	size_t	tmp;

	srclen = ft_strlen(src);
	destlen = ft_strlen((const char *)dest);
	res = srclen + destlen;
	tmp = srclen - (res - (n - 1));
	if (n <= destlen)
		return (n + srclen);
	if (res < n)
		ft_strcat(dest, src);
	else
		ft_strncat(dest, src, tmp);
	return (res);
}
