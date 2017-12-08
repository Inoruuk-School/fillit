# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ybarraul <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/23 10:16:48 by ybarraul     #+#   ##    ##    #+#        #
#    Updated: 2017/12/06 12:39:37 by ybarraul    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fillit
CC = gcc
FLAGS = -Wall -Wextra -Werror

FILES =

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
