/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c1_verif_tet.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:28:37 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 12:28:40 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
 * Verifie chaque coordonnee de chaque tetri *
*/
char			pos_tet(t_each_tet *tet, int x, int y)
{
	int		i;
	
	i = 0;
	while (i < 4)
	{
		if ((tet -> crds[i].x == x) && (tet -> crds[i].y == y))
			return (1);
		i++;
	}
	return (0);
}

/*
 * Regarde les 3 cases autour *
*/
static char		verif_tier(t_eachtet *tet,int x, int y)
{
	int		cas;

	cas = 0;
	cas = cas + ((pos_tet(tet, x + 1, y)) && (pos_tet(tet, x + 2, y)));
	cas = cas + ((pos_tet(tet, x + 1, y)) && (pos_tet(tet, x + 1, y + 1)));
	cas = cas + ((pos_tet(tet, x + 1, y)) && (pos_tet(tet, x + 1, y - 1)));
	cas = cas + ((pos_tet(tet, x - 1, y)) && (pos_tet(tet, x - 2, y)));
	cas = cas + ((pos_tet(tet, x - 1, y)) && (pos_tet(tet, x - 1, y + 1)));
	cas = cas + ((pos_tet(tet, x - 1, y)) && (pos_tet(tet, x - 1, y - 1)));
	cas = cas + ((pos_tet(tet, x, y + 1)) && (pos_tet(tet, x, y + 2)));
	cas = cas + ((pos_tet(tet, x, y + 1)) && (pos_tet(tet, x + 1, y + 1)));
	cas = cas + ((pos_tet(tet, x, y + 1)) && (pos_tet(tet, x - 1, y + 1)));
	cas = cas + ((pos_tet(tet, x, y - 1)) && (pos_tet(tet, x, y - 2)));
	cas = cas + ((pos_tet(tet, x, y - 1)) && (pos_tet(tet, x + 1, y - 1)));
	cas = cas + ((pos_tet(tet, x, y - 1)) && (pos_tet(tet, x - 1, y - 1)));
	return (cas);
}

/*
 * Regarde si la case est bien a cote d'un autre *
 * Verifie les cases adjacents
*/
static char		verif_duo(t_each_tet *tet)
{
	int		i;
	char	x;
	char	y;
	int		cas;

	i = 0;
	while (i < 4)
	{
		x = tet -> crds[i].x;
		y = tet -> crds[i].y;
		cas = pos_tet(tet, x + 1, y) + pos_tet(tet, x, y + 1);
		cas = cas + pos_tet(tet, x - 1, y) + pos_tet(tet, x, y - 1);
		if (cas >= 2)
			return (1);
		cas = verif_tier(tet, x, y);
		if (!cas)
			return (0);
	}
	return (1);
}

/*
 * Regarde si la case n'est pas seul (rien autour) *
*/
static char		verif_solo(t_each_tet *tet)
{
	int		i;
	int		cas;

	i = 0;
	while (i < 4)
	{
		cas = 0;
		cas = cas + pos_tet(tet, tet -> crds[i].x + 1, tet -> crds[i].y);
		cas = cas + pos_tet(tet, tet -> crds[i].x, tet -> crds[i].y + 1);
		cas = cas + pos_tet(tet, tet -> crds[i].x - 1, tet -> crds[i].y);
		cas = cas + pos_tet(tet, tet -> crds[i].x, tet -> crds[i].y - 1);
		if (!cas)
			return (0);
		i++;
	}
	return (1);
}

/*
 * Regarde chaque tetri pour savoir si il est valable *
 * Verifie les cas isolees *
 * Verifie les cas particuliers *
*/
char			verif_tet(t_eachtet *memtet)
{
	int		i;

	i = 0;
	while (i < memtet -> nb_tet)
	{
		if (!verif_solo(&memtet ->list_tet[i]))
			return (0);
		if (!verif_duo(&memtet ->list_tet[i]))
			return (0);
		i++;
	}
	return (1)
}
