/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ybarraul <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 11:31:00 by ybarraul     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/06 12:32:07 by ybarraul    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>

typedef struct		s_coord
{
	char			x;
	char			y;
}					t_coord;

typedef struct				s_onetet
{
	t_coord			crds[4];
	long			size;
	char			x;
	char			y;
	char			width;
	char			height;
	int				last;
}					t_onetet;

typedef struct				s_eachtet
{
	t_onetet		list_tet[26];
	char			nb_tet;
	char			size_each;
}					t_eachtet;

void    			init_memtet(t_eachtet *memtet);
void				exit_close(int fd);
void				check_all(t_eachtet memtet, int fd);
static void			check_list(t_eachtet memtet, int fd);
static t_onetet		check_tet(char str, int fd);
static int			check_coord(t_coord *crds, int i, char c, int fd);
char				verif_tet(t_eachtet *memtet);
static char			verif_solo(t_eachtet *tet);
static char			verif_duo(t_eachtet *tet);
static char			verif_tier(t_eachtet *tet,int x, int y);
char				pos_tet(t_eachtet *tet, int x, int y);
void				move_tet(t_eachtet *tet);
static void			corners(t_eachtet *tet);
void				size_tet(t_eachtet *memtet);
static void 		mesure_tet(t_eachtet *tet);
static long			the_size(t_eachtet *tet);
static char			swap(char a, char b);
void				der_tet(t_eachtet *memtet);
void				the_last(t_eachtet memtet, int n);
char				idm_tet(t_onetet tet1, t_onetet tet2);
void				resolve(t_eachtet *memtet);
static void			resolve_bis(t_eachtet *memtet, int map, int n);
static void			check_map(t_onetet *tet, int *map);
static void			ver_tet(t_onetet *tet, int *map);
void				ft_bzero(void *s, size_t n);
void				print_tet(t_eachtet *memtet);
static void			print_alpha(t_eachtet *memtet, int x, int y);
void				ft_putchar(char c);

#endif