/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 12:08:21 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 12:08:27 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int main (int ac, char **av)
{
	t_eachtet	memtet;
	int			fd;

	init_memtet(&memtet);
	if ((ac != 2) || (fd = open(av[1], O_RDONLY)) < 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	ft_check_all(&memtet, fd);
//	resolve(&memtet);
	print_tet(&memtet);
	close(fd);
	return (0);
}