/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 02:15:57 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/28 15:31:18 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			main()
{
	int		ch;
	int		exit;
	t_win	win;

	win = get_win_size();//get term size
	srand(time(NULL));
	if (getenv ("ESCDELAY") == NULL)//par defaut ncurses a un delay sur la touche echap
		ESCDELAY = 25;//du coup le delay est redefini a 25ms pour fluidifier le retour au menu
	ch = 0;//touche appuye
	g_glob.state = 0;//0: dans le menu, 1: en jeu
	g_glob.current = 0;//0 aucune partie joue, 4: partie 4x4 en cours, 5: 5x5
	exit = 0;//flag pour la sortie du programme
	init_menu(&(g_glob.menu));//init des data du menu
	signal(SIGWINCH, &resize);//catch signal resize et appel de la fonction resize()
	initscr();// init ncurses
	start_color();//init colors ncurses
	use_default_colors();//avec cette fonction en mettant -1 pour une couleur ca mettra la couleur par default du terminal
	init_pair(1, -1, -1);//creation de pair de couleur, id, couleur du texte, couleur du fond
	init_pair(2, COLOR_WHITE, -1);//c'est pour ca que tout est blanc chez toi
	init_pair(3, COLOR_GREEN, -1);
	curs_set(0);//curseur invisible
	raw();//desactivation du buffer (je sais pas trop ce que ca fait en fait)
	keypad(stdscr, TRUE);//pour pouvoir catcher des touches supplementaires (f1...)
	noecho();//pas d'affichage des touches appuyes
	print_menu(&(g_glob.menu), win);//on ecrit le menu
	refresh();//on actualise (ca va afficher le menu du coup)
	while (!exit && (ch = getch()))//tant que le flag exit est a 0 on va attendre un appui sur une touche
	{
		if (!g_glob.state && ch != KEY_RESIZE)//si state == 0 (on est dans le menu) le KEY_RESIZE c'est un test non concluant
		{
			if (ch == KEY_UP)//si touche du haut
				prev_menu_pos(&(g_glob.menu));//on deplace la position du curseur vers le haut
			if (ch == KEY_DOWN)//pareil pour le bas
				next_menu_pos(&(g_glob.menu));
			print_menu(&(g_glob.menu), win);//on reecrit le menu
			refresh();//on rafraichi
			if (ch == 10 && g_glob.menu.pos == (g_glob.menu.nb_ch - 1))//si touche entree et curseur sur exit
				exit = 1;//on sort de l'appli
			if (ch == 10 && g_glob.menu.pos == 0)//si touche entree et curseur sur 4x4
			{
				erase();//on efface le menu
				init_play4(&(g_glob.p4));//on initialise une nouvelle partie
				g_glob.current = 4;//current => 4 => partie 4x4 en cours
				g_glob.menu.enabled[2] = 1;//on rend actif le choix 'resume game' dans le menu
				print_play4(&(g_glob.p4), win);//on affiche le 4x4
				refresh();//on rafraichie,  je pense que tu avais compris!!!
				g_glob.state = 1;//state=>1=>en jeu
			}
			if (ch == 10 && g_glob.menu.pos == 2)//si touche entre et curseur sur resume
			{
				erase();//on efface le menu
				if (g_glob.current == 4)//si une partie 4x4 est en cours
					print_play4(&(g_glob.p4), win);//on ecrit la partie en cours
				refresh();//on rafraichie
				g_glob.state = 1;//state => 1 => en jeu
			}
		}
		else if (g_glob.state == 1 && g_glob.current == 4 && ch != KEY_RESIZE)//si state == 1 (en jeu) et que current == 4 (4x4)
		{
			print_play4(&(g_glob.p4), win);//on ecrit la partie 4x4
			refresh();//on rafraichie
			if(ch == 27)//si touche echap
			{
				erase();//on efface la partie
				g_glob.menu.pos = 0;//on remet le curseur du menu en position initiale
				print_menu(&(g_glob.menu), win);//on affiche le menu
				refresh();//on raffraichie
				g_glob.state = 0;//on passe l'etat a 0 => dans le menu
			}
		}
	}
	curs_set(1);//on reaffiche le curseur avec de sortir
	endwin();// on ferme ncurses
	return (0);
}
