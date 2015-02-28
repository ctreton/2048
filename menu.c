/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 02:22:00 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/28 06:37:07 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		print_menu(t_menu *menu, t_win win)
{
	print_menu_frame(win);
	print_menu_text(menu, win);
}

void		print_menu_frame(t_win win)
{
	int		i;

	i = 0;
	while(i < win.x)
	{
		mvaddch(0, i, '#');
		mvaddch(win.y - 1, i, '#');
		i++;
	}
	i = 0;
	while(i < win.y)
	{
		mvaddch(i, 0, '#');
		mvaddch(i, win.x - 1, '#');
		i++;
	}
}

void		print_menu_text(t_menu *menu, t_win win)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	attron(COLOR_PAIR(3));
	mvaddstr(0, ((win.x - 1) / 2) - 5, menu->title);
	attroff(COLOR_PAIR(3));
	while(i < menu->nb_ch)
	{
		if(menu->pos == i)
			attron(A_UNDERLINE);
		if(menu->enabled[i] == 1)
			attron(COLOR_PAIR(2));
		x = ((win.x - 1) / 2) - (ft_strlen(menu->ch[i]) / 2);
		mvaddstr(((i * 2) + 2), x, menu->ch[i]);
		attroff(COLOR_PAIR(2) | A_UNDERLINE);
		i++;
	}
}

void		init_menu(t_menu *menu)
{
	menu->title = " GAME 2048 ";
	menu->nb_ch = 4;
	menu->pos = 0;
	menu->ch = (char **)malloc(sizeof(char*) * menu->nb_ch);
	menu->ch[0] = "Play 4x4";
	menu->ch[1] = "Play 5x5";
	menu->ch[2] = "Resume game";
	menu->ch[3] = "Exit game";
	menu->enabled = (int *)malloc(sizeof(int) * menu->nb_ch);
	menu->enabled[0] = 1;
	menu->enabled[1] = 0;
	menu->enabled[2] = 0;
	menu->enabled[3] = 1;
}

void		prev_menu_pos(t_menu *menu)
{
	menu->pos = (menu->pos - 1) < 0 ? menu->nb_ch - 1 : menu->pos - 1;
	while(menu->enabled[menu->pos] == 0)
		menu->pos = (menu->pos - 1) < 0 ? menu->nb_ch - 1 : menu->pos - 1;
}

void		next_menu_pos(t_menu *menu)
{
	menu->pos = (menu->pos + 1) == menu->nb_ch ? 0 : menu->pos + 1;
	while(menu->enabled[menu->pos] == 0)
		menu->pos = (menu->pos + 1) == menu->nb_ch ? 0 : menu->pos + 1;
}








