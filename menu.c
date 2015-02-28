/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 02:22:00 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/28 15:29:13 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void		print_menu(t_menu *menu, t_win win)//affichage du menu
{
	print_menu_frame(win);//affichage du cadre en #, trop classe pour toi!
	print_menu_text(menu, win);//affichage du titre et des choix du menu
}

void		print_menu_frame(t_win win)//affichage du cadre trop beau pour toi
{
	int		i;

	i = 0;
	while(i < win.x)//affichage des lignes
	{
		mvaddch(0, i, '#');
		mvaddch(win.y - 1, i, '#');
		i++;
	}
	i = 0;
	while(i < win.y)//affichage des colonnes
	{
		mvaddch(i, 0, '#');
		mvaddch(i, win.x - 1, '#');
		i++;
	}
}

void		print_menu_text(t_menu *menu, t_win win)//la on affiche le texte t'as vu!
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	attron(COLOR_PAIR(3));//on passe en couleur, tu te souviens les init pair color? bah voila a quoi ca sert, la c'est la 3, donc vert sur font par default
	mvaddstr(0, ((win.x - 1) / 2) - 5, menu->title);//on ecrit le titre en haut
	attroff(COLOR_PAIR(3));//on arrete la couleur
	while(i < menu->nb_ch)//on affiche les choix
	{
		if(menu->pos == i)//si le curseur est sur ce choix on le souligne
			attron(A_UNDERLINE);//souligne ON, GO GO GO!!!
		if(menu->enabled[i] == 1)//si le choix est dispo on le colore
			attron(COLOR_PAIR(2));//WHITE WHITE WHITE
		x = ((win.x - 1) / 2) - (ft_strlen(menu->ch[i]) / 2);//on se place au milieu histoire d'ecrire centre
		mvaddstr(((i * 2) + 2), x, menu->ch[i]);//on ecrit comme il faut
		attroff(COLOR_PAIR(2) | A_UNDERLINE);//on supprime le soulignement et la couleur, au bucher!
		i++;// on incremente la variable i de 1, pour pas se retrouver dans une situation de boucle infini et de segfault
	}
}

void		init_menu(t_menu *menu)//initialisation du menu, j'ai pas trouve mieux comme facon de faire :/
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

void		prev_menu_pos(t_menu *menu)//on change la position du curseur vers l'arriere
{
	menu->pos = (menu->pos - 1) < 0 ? menu->nb_ch - 1 : menu->pos - 1;
	while(menu->enabled[menu->pos] == 0)
		menu->pos = (menu->pos - 1) < 0 ? menu->nb_ch - 1 : menu->pos - 1;
}

void		next_menu_pos(t_menu *menu)//on change la position du curseur vers l'avant
{
	menu->pos = (menu->pos + 1) == menu->nb_ch ? 0 : menu->pos + 1;
	while(menu->enabled[menu->pos] == 0)
		menu->pos = (menu->pos + 1) == menu->nb_ch ? 0 : menu->pos + 1;
}








