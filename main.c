/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 02:15:57 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/28 08:59:11 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			main()
{
	int		ch;
	int		exit;
	t_win	win;

	win = get_win_size();
	srand(time(NULL));
	if (getenv ("ESCDELAY") == NULL)
		ESCDELAY = 25;
	ch = 0;
	g_glob.state = 0;
	g_glob.current = 0;
	exit = 0;
	init_menu(&(g_glob.menu));
	signal(SIGWINCH, &resize);
	initscr();
	start_color();
	use_default_colors();
	init_pair(1, -1, -1);
	init_pair(2, COLOR_WHITE, -1);
	init_pair(3, COLOR_GREEN, -1);
	curs_set(0);
	raw();
	keypad(stdscr, TRUE);
	noecho();
	print_menu(&(g_glob.menu), win);
	refresh();
	while (!exit && (ch = getch()))
	{
		if (!g_glob.state && ch != KEY_RESIZE)
		{
			if (ch == KEY_UP)
				prev_menu_pos(&(g_glob.menu));
			if (ch == KEY_DOWN)
				next_menu_pos(&(g_glob.menu));
			print_menu(&(g_glob.menu), win);
			refresh();
			if (ch == 10 && g_glob.menu.pos == (g_glob.menu.nb_ch - 1))
				exit = 1;
			if (ch == 10 && g_glob.menu.pos == 0)
			{
				erase();
				init_play4(&(g_glob.p4));
				g_glob.current = 4;
				g_glob.menu.enabled[2] = 1;
				print_play4(&(g_glob.p4), win);
				refresh();
				g_glob.state = 1;
			}
			if (ch == 10 && g_glob.menu.pos == 2)
			{
				erase();
				if (g_glob.current == 4)
					print_play4(&(g_glob.p4), win);
				refresh();
				g_glob.state = 1;
			}
		}
		else if (g_glob.state == 1 && g_glob.current == 4 && ch != KEY_RESIZE)
		{
			print_play4(&(g_glob.p4), win);
			refresh();
			if(ch == 27)
			{
				erase();
				g_glob.menu.pos = 0;
				print_menu(&(g_glob.menu), win);
				refresh();
				g_glob.state = 0;
			}
		}
	}
	curs_set(1);
	endwin();
	return (0);
}
