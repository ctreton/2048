/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 02:14:31 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/28 08:40:38 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <ncurses.h>
# include <stdlib.h>
# include <time.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "libft.h"

enum				e_const
{
	WIN_VALUE = 2048
};

typedef struct		s_win
{
	int				x;
	int				y;
}					t_win;

typedef struct		s_menu
{
	char			*title;
	int				nb_ch;
	char			**ch;
	int				*enabled;
	int				pos;
}					t_menu;

typedef struct		s_tile
{
	int				index;
	int				x;
	int				y;
	int				value;
	struct s_tile	*next;
}					t_tile;

typedef struct		s_play4
{
	t_tile			*start;
	int				round;
}					t_play4;

typedef struct		s_glob
{
	int				current;
	int				state;
	t_menu			menu;
	t_play4			p4;
}					t_glob;

t_glob		g_glob;

void				print_menu(t_menu *menu, t_win win);
void				print_menu_frame(t_win win);
void				print_menu_text(t_menu *menu, t_win win);
void				init_menu(t_menu *menu);
void				prev_menu_pos(t_menu *menu);
void				next_menu_pos(t_menu *menu);
t_win				get_win_size(void);
void				resize(int a);
void				init_play4(t_play4 *p4);
t_tile				*new_tile(int i);
void				print_play4(t_play4 *p4, t_win win);
void				print_play4_frame(t_win win);
void				print_play4_tiles(t_play4 *p4, t_win win);
t_tile				*find_tile_by_index(t_tile *start, int i);



#endif
