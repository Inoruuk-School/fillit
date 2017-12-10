/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   resolve.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:30:02 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 12:30:03 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void			ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
		str[i++] = 0;
}

/*
** check tetri **
*/
static void		ver_tet(t_onetet *tet, int *map)
{
	*((long *)(map + tet -> y)) ^= (tet -> size << tet -> x);
}
/*
** check map **
*/

static void		check_map(t_onetet *tet, int *map)
{
	return (!((*(long *)(map + tet -> y)) & (tet -> size << tet -> x)));
}

/*
** Back traking sur les tetri **
 * Verifie par report a la map *
 * Verifie par report au tetri *
*/
static void		resolve_bis(t_eachtet *memtet, int map, int n)
{
	t_onetet	*tet;

	tet = &(memtet -> list_tet[n]);
	tet -> y = (tet -> last >= 0 ? memtet -> list_tet[tet -> last].y : 0);
	tet -> x = (tet -> last >= 0 ? memtet -> list_tet[tet -> last].x + 1 : 0);
	while (tet -> y + tet -> height < memtet -> nb_list)
	{
		while (tet -> x + tet -> width < memtet -> size_each)
		{
			if (check_map(tet , map))
			{
				ver_tet(tet, map);
				if (n + 1 == memtet -> nb_tet)
					return (1);
				else if (resolve_bis(memtet, map, n + 1))
					return (1);
				ver_tet(tet, map);
			}
			tet -> x++;
		}
		tet -> x = 0;
		tet -> y++;
	}
	return (0);
}

/*
** Creer la map **
 * Calcul si tous les tetri peuvent etre placer *
*/
void			resolve(t_eachtet *memtet)
{
	int		map[16];

	ft_bzero(map, sizeof(int) * 16);
	memtet -> size_each = 2;
	while (memtet -> size_each * memtet -> size_each < 4 * memtet -> nb_tet)
		memtet -> size_each++;
	while (!resolve_bis(memtet, map, 0) && memtet -> size_each < 16)
	{
		ft_bzero(map, sizeof(int) * 16);
		memtet -> size_each++;
	}
}
