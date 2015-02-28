/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 02:06:55 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/28 02:07:21 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
		return (ptr);
	new_ptr = malloc(size);
	ft_bzero(new_ptr, size);
	ft_memcpy(new_ptr, ptr, (size_t)(ft_strlen((char *)(ptr))));
	free(ptr);
	return (new_ptr);
}
