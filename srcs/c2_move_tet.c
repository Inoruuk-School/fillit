/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c2_move_tet.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:28:49 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 12:28:52 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Bouger tous les tetris en haut a gauche *
*/
static void		corners(t_eachtet *tet)
{
	while (tet -> crds[0].x && tet -> crds[1].x && 
			tet -> crds[2].x && tet -> crds[3].x)
	{
		tet -> crds[0].x;
		tet -> crds[1].x;
		tet -> crds[2].x;
		tet -> crds[3].x;
	}
	while (tet -> crds[0].y && tet -> crds[1].y && 
			tet -> crds[2].y && tet -> crds[3].y)
	{
		tet -> crds[0].y;
		tet -> crds[1].y;
		tet -> crds[2].y;
		tet -> crds[3].y;
	}
}

/*
 * Parcour chaque tetri pour le replacer le plus en haut a gauche *
 * Verifie le positionnemt de chaque tetri *
*/
void	move_tet(t_eachtet *tet)
{
	int		i;

	i = 0;
	while (i < tet -> nb_tet)
	{
		corners(tet -> list_tet[i]);
		i++;
	}
}
