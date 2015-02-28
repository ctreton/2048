/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctreton <ctreton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 06:23:30 by ctreton           #+#    #+#             */
/*   Updated: 2015/02/28 15:14:55 by ctreton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			init_play4(t_play4 *p4)//initialisation d'une partie
{
	t_tile		*tmp;
	int			i;
	int			j;

	i = 0;
	p4->round = 0;//le nombre de round
	p4->start = new_tile(0);//on cree une tuile
	tmp = p4->start;
	while (i < 15)//puis 15 autres, ca fait 16 en tout (4x4), ca va? tu suis?
	{
		tmp->next = new_tile(i + 1);
		tmp = tmp->next;
		i++;
	}
	i = rand() % 16;//random entre 0 et 15
	tmp = find_tile_by_index(p4->start, i);//on prend la tuile correspondante
	tmp->value = rand() % 2 ? 4 : 2;//on lui attribue la valeur 2 ou 4
	j = i;
	while (j == i)//la on fait pareil en verifiant qu'on reprend pas la meme
		j = rand() % 16;
	tmp = find_tile_by_index(p4->start, j);
	tmp->value = rand() % 2 ? 4 : 2; 
}

t_tile			*new_tile(int i)//creation d'une tuile
{
	t_tile		*tile;//il me semble que ca se passe de commentaire

	tile = (t_tile *)malloc(sizeof(t_tile));
	tile->index = i;
	tile->x = i % 4;
	tile->y = i / 4;
	tile->value = 0;// valeur par default pour une tuile vide
	tile->next = NULL;
	return (tile);
}

void			print_play4(t_play4 *p4, t_win win)//affichage de la grille 4x4
{
	print_play4_frame(win);//affichage du cadre
	print_play4_tiles(p4, win);//affichage des tuiles (>0)
}

void			print_play4_frame(t_win win)//affichage du cadre
{
	int		i;

	win.x = ((((win.x - 5) / 4) * 4) + 5);//on redefini winX et winY pour que les tuiles aient toutes la meme taille
	win.y = ((((win.y - 5) / 4) * 4) + 5);
	i = 0;
	while(i < win.x)//pour les lignes
	{
		mvaddch(0, i, '#');
		mvaddch((((win.y - 2) / 4) * 1) + 1, i, '#');
		mvaddch((((win.y - 2) / 4) * 2) + 2, i, '#');
		mvaddch((((win.y - 2) / 4) * 3) + 3, i, '#');
		mvaddch(win.y - 1, i, '#');
		i++;
	}
	i = 0;
	while(i < win.y)//pour les colonnes
	{
		mvaddch(i, 0, '#');
		mvaddch(i, (((win.x - 2) / 4) * 1) + 1, '#');
		mvaddch(i, (((win.x - 2) / 4) * 2) + 2, '#');
		mvaddch(i, (((win.x - 2) / 4) * 3) + 3, '#');
		mvaddch(i, win.x - 1, '#');
		i++;
	}
}

void			print_play4_tiles(t_play4 *p4, t_win win)//affichage des tuiles
{
	t_tile		*tile;
	int			x;
	int			y;

	x = 0;
	y = 0;
	win.x = ((((win.x - 5) / 4) * 4) + 5);//on redefini les tuiles bla bla bla comme au dessus
	win.y = ((((win.y - 5) / 4) * 4) + 5);
	tile = p4->start;
	while (tile)//pour chaque tuile
	{
		if (tile->value)
		{
			x = ((((win.x - 2) / 4) * tile->x) + tile->x);//x est tout a gauche de la tuile
			x += (win.x - 5) / 8;//x est au milieu de la tuile
			x -= ((ft_strlen(ft_itoa(tile->value)) - 1) / 2);//x recule pour centrer le nombre
			y = ((((win.y - 2) / 4) * tile->y) + tile->y);//y est en haut de la tuile
			y += (win.y - 5) / 8;//y est au milieu... IMPEC
			mvaddstr(y, x, ft_itoa(tile->value));//on affiche le nombre aux coordonnees... faicle
		}
		tile = tile->next;
	}
}

t_tile			*find_tile_by_index(t_tile *start, int i)//petite fonction qui retourne la tuile de l'index donne... son nom est assez explicite il me semble...
{
	t_tile	*tile;

	tile = start;
	while(tile && tile->index != i)
	{
		tile = tile->next;
	}
	return (tile);
}
