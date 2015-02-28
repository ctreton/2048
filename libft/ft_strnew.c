/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 05:47:52 by ctreton           #+#    #+#             */
/*   Updated: 2013/11/30 03:24:55 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*res;

	size++;
	res = (char *)malloc(sizeof(char *) * size);
	if (res)
	{
		ft_memset(res, 0, size);
		return (res);
	}
	else
		return (NULL);
}
