##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	= src/my_ls.c		\
	lib/my/my_put_nbr.c	\
	lib/my/my_putchar.c	\
	lib/my/my_putstr.c	\
	src/choose_flag.c	\
	src/my_strlen.c		\
	src/path.c


OBJ		=	$(SRC:.c=.o)
      
NAME	=	my_ls

CPPFLAGS =	-I ./include/

CFLAGS	=	-Wall -Wextra

LDLIBS	=	-lmy

LDFLAGS	=	-L./lib/my

RM	= rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) -g3

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all


.PHONY: all clean