/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 06:23:30 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/28 07:45:37 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			init_play4(t_play4 *p4)
{
	t_tile		*tmp;
	int			i;
	int			j;

	i = 0;
	p4->round = 0;
	p4->start = new_tile(0);
	tmp = p4->start;
	while (i < 15)
	{
		tmp->next = new_tile(i + 1);
		tmp = tmp->next;
		i++;
	}
	i = rand() % 16;
	tmp = find_tile_by_index(p4->start, i);
	tmp->value = rand() % 2 ? 4 : 2;
	j = i;
	while (j == i)
		j = rand() % 16;
	tmp = find_tile_by_index(p4->start, j);
	tmp->value = rand() % 2 ? 4 : 2; 
}

t_tile			*new_tile(int i)
{
	t_tile		*tile;

	tile = (t_tile *)malloc(sizeof(t_tile));
	tile->index = i;
	tile->x = i % 4;
	tile->y = i / 4;
	tile->value = 0;
	tile->next = NULL;
	return (tile);
}

void			print_play4(t_play4 *p4)
{
	t_win		win;

	win = get_win_size();
	print_play4_frame(win);
	print_play4_tiles(p4, win);
}

void			print_play4_frame(t_win win)
{
	int		i;

	win.x = ((((win.x - 5) / 4) * 4) + 5);
	win.y = ((((win.y - 5) / 4) * 4) + 5);
	i = 0;
	while(i < win.x)
	{
		mvaddch(0, i, '#');
		mvaddch((((win.y - 2) / 4) * 1) + 1, i, '#');
		mvaddch((((win.y - 2) / 4) * 2) + 2, i, '#');
		mvaddch((((win.y - 2) / 4) * 3) + 3, i, '#');
		mvaddch(win.y - 1, i, '#');
		i++;
	}
	i = 0;
	while(i < win.y)
	{
		mvaddch(i, 0, '#');
		mvaddch(i, (((win.x - 2) / 4) * 1) + 1, '#');
		mvaddch(i, (((win.x - 2) / 4) * 2) + 2, '#');
		mvaddch(i, (((win.x - 2) / 4) * 3) + 3, '#');
		mvaddch(i, win.x - 1, '#');
		i++;
	}
}

void			print_play4_tiles(t_play4 *p4, t_win win)
{
	t_tile		*tile;
	int			x;
	int			y;

	x = 0;
	y = 0;
	win.x = ((((win.x - 5) / 4) * 4) + 5);
	win.y = ((((win.y - 5) / 4) * 4) + 5);
	tile = p4->start;
	while (tile)
	{
		if (tile->value)
		{
			x = ((((win.x - 2) / 4) * tile->x) + tile->x);
			x += (win.x - 5) / 8;
			x -= ((ft_strlen(ft_itoa(tile->value)) - 1) / 2);
			y = ((((win.y - 2) / 4) * tile->y) + tile->y);
			y += (win.y - 5) / 8;
			mvaddstr(y, x, ft_itoa(tile->value));
		}
		tile = tile->next;
	}
}

t_tile			*find_tile_by_index(t_tile *start, int i)
{
	t_tile	*tile;

	tile = start;
	while(tile && tile->index != i)
	{
		tile = tile->next;
	}
	return (tile);
}
