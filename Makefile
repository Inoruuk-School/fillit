# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ybarraul <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/23 10:16:48 by ybarraul     #+#   ##    ##    #+#        #
#    Updated: 2017/12/08 18:34:40 by asiaux      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror

FILES = c0_init__exit_close.c c1_verif_tet.c c2_move_tet.c c3_size_tet.c c4_der_tet.c \
		check_all.c main.c print_tet.c solve.c

INCLUDEDIR = includes/

SRCDIR = srcs/
SRC = $(addprefix $(SRCDIR), $(FILES))

OBJDIR = objs/
OBJ = $(addprefix $(OBJDIR) $(FILES: .c = .o))

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)%.o : $(SRCDIR)%.c
		mkdir -p $(OBJDIR)
		$(CC) -c $^ $(FLAGS) -o %@ -I $(INCLUDEDIR)
		ranlib $(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
