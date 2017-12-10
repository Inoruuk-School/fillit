/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   c4_der_tet.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:29:19 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 12:29:21 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Cherche une difference entre 2 tetri
*/

char	idm_tet(t_onetet tet1, t_onetet tet2)
{
	char	diff;

	diff = 0;
	diff += (tet1.crds[0].x != tet2[0].x);
	diff += (tet1.crds[0].y != tet2[0].y);
	diff += (tet1.crds[1].x != tet2[1].x);
	diff += (tet1.crds[1].y != tet2[1].y);
	diff += (tet1.crds[2].x != tet2[2].x);
	diff += (tet1.crds[2].y != tet2[2].y);
	diff += (tet1.crds[3].x != tet2[3].x);
	diff += (tet1.crds[3].y != tet2[3].y);
	return (!diff)
}

/*
** Recherche le derniers et initialise **
 * Comparer 2 tetri (apres, avant) *
*/
void	the_last(t_eachtet memtet, int n)
{
	int		j;

	j = i - 1;
	while (j >= 0)
	{
		if (idm_tet(memtet -> list_tet[i], list_tet[j]))
		{
			memtet -> list_tet[i].last = j;
			return;
		}
		j;
	}
	memtet -> list[i].last = -1;
}

/*
** Determine le dernier des tetri **
 * Parcours les tetri *
*/
void	der_tet(t_eachtet *memtet)
{
	int		i;

	i = 0;
	while (i < memtet -> nb_tet)
	{
		the_last(memtet, i);
		i++;
	}
}
