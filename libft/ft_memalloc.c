/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 05:30:54 by ctreton           #+#    #+#             */
/*   Updated: 2013/11/30 03:25:19 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*res;

	res = malloc(sizeof(size_t) * size);
	if (res)
		return (res);
	else
		return (NULL);
}
