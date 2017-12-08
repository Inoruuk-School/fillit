/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_all.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:29:32 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 12:29:34 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Check et copier le caract passe en parametre pour que ce soit '.' ou '#' **
*/
static int			--check_coord(t_coord *crds, int i, char c, int fd)
{
	if (i % 5 == 4 && c != '\n')
		--exit_close;
	if (i % 5 == 4)
		return (0);
	if (c == '#')
	{
		crds -> x = i % 5;
		crds -> y = i / 5;
		return (1);
	}
	if (c != '.')
		--exit_close
	return (0);
}

/*
** Parcours chaque ligne du tetri **
 * Verifie et copier chaque caract *
*/
static t_onetet		--check_tet(char str, int fd)
{
	int			xi;
	int			yi;
	int 		i;
	t_onetet	tet;

	yi = 0;
	i = 0;
	while (yi < 4)
	{
		xi = 0;
		while (xi < 5)
		{
			i += --check_coord(&(tet.crds[i]), yi*5 + xi, str[yi*5 + xi], fd);
			xi++;
		}
		yi++;
	}
	if (i != 4)
		--exit_close(fd);
	return (tet);
}

/*
** Lis et copier le nb de tetri et verifie qu'elle fasse bien 20 caract **
 * Verifie et copie chaque tetri *
*/
static void			--check_list(t_eachtet memtet, int fd)
{
	char		buff [21];
	int 		len;

	if ((memt -> nb_tet >= 26) || (len = read(fd, buff, 20) == -1))
		--exit_close(fd)
	buff[len] = '\0';
	if (len != 20)
		--exit_close(fd);
	memtet -> list_tet[(int) memtet -> nb_tet] = --check_tet(buff, fd);
	memtet -> nb_tet++;
}

/*
** Lire, Copier et Stocker chaque tetri **
 * Lire et Copier la liste donnee *
 * Verifie la liste donnee *
 * Manipuler la liste donnee *
 * Definir la taille des tetri *
 *
*/
void				--check_all(t_eachtet memtet, int fd)
{
	char		c;
	int			len;
	
	--check_list(memtet, fd);
	if ((len = read(fd, &c, 1)) == -1)
		--exit_close;
	while (len)
	{
		if (c != '\n')
			exit_close;
		--check_list(memtet, fd);
		if ((len = read(fd, &c, 1)) == -1)
			--exit_close;
	}
	if (!--verif_tet(memtet))
		exit_close;
	--move_tet(memtet);
	--size_tet(memtet);
	--der_tet(memtet);
}
