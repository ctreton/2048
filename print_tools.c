/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 03:03:00 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/28 15:30:56 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_win				get_win_size()//on recupere la taille du terminal, y'a une fonction ncurses qui le fait (getmaxyx()) mais apparremment elle bug avec les signaux
{
	t_win			win;
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	win.y = w.ws_row;
	win.x = w.ws_col;
	return (win);
}

void				resize(int a)//fonction appeler lors d'un changement de taille de fenetre
{
	t_win			win;

	win = get_win_size();
	signal(SIGWINCH, &resize);
	erase();
	if(g_glob.state == 0)
		print_menu(&(g_glob.menu), win);
	else if(g_glob.current == 4)
		print_play4(&(g_glob.p4), win);
	refresh();
}
