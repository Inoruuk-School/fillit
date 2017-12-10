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

OBJS = c0_init__exit_close.o c1_verif_tet.o c2_move_tet.o c3_size_tet.o c4_der_tet.o \
		check_all.o main.o print_tet.o solve.o

INCLUDEDIR = includes/

SRCDIR = srcs/
SRC = $(addprefix $(SRCDIR), $(FILES))

#OBJDIR = objs/
#OBJ = $(addprefix $(OBJDIR) $(OBJS))

all : $(NAME)

$(NAME) : 
		$(CC) $(FLAGS) -o $(NAME) $(SRC) -I $(INCLUDEDIR)

$(OBJDIR)%.o : $(SRCDIR)%.c
		mkdir -p $(OBJDIR)
		$(CC) -c $^ $(FLAGS) -o %@ -I $(INCLUDEDIR)
		ranlib $(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all
