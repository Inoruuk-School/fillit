/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_tet.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:29:49 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 12:29:51 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include "unistd.h"

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** Affiche les lettres de chaque tetri
*/
static void		--print_alpha(t_eachtet *memtet, int x, int y)
{
	int		i;

	i = 0;
	while (i < memtet -> nb_tet)
	{
		if (pos_tet(&memtet -> list_tet[i], x - memtet -> list[i].x,
											y - memtet -> list[i].y))
		{
			ft_putchar('A' + i);
			return ();
		}
		i++;
	}
	ft_putchar('.');
}

/*
** Affiche les lignes de la map resolu **
 * Determine la lettre a afficher *
*/
void			--print_tet(t_eachtet *memtet)
{
	int		xi;
	int		yi;

	yi = 0;
	while (yi < memtet -> size_each)
	{
		xi = 0;
		while (yi < memtet -> size_each)
		{
			--print_alpha(memtet, xi, yi);
			xi++;
		}
		ft_putchar('\n');
		yi++;
	}
}
