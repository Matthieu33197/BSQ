##
## EPITECH PROJECT, 2019
## make
## File description:
## files
##

SRC	=	mem_alloc_2d_array.c	\
		my_malloc.c		\
		my_strlen.c 		\
		my_put_nbr.c		\
		my_putchar.c		\
		my_putstr.c		\
		my_strcpy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include
	cp my.h -p ../../include/

clean:
		rm -rf *.o

fclean:		clean

