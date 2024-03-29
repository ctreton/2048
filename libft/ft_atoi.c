/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 22:12:43 by ctreton           #+#    #+#             */
/*   Updated: 2013/12/01 18:07:22 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int			ft_atoi(const char *s)
{
	int		res;
	int		neg;
	int		i;

	i = 0;
	res = 0;
	neg = 1;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
		neg = (s[i++] == '-' ? -1 : 1);
	while (s[i] == '0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res = (10 * res) + (s[i] - '0');
			i++;
		}
		else
			return (res * neg);
	}
	return (res * neg);
}
