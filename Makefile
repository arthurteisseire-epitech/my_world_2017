##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##  Ozz
##

DSRC	=	$(realpath ./src)/
SRC	=	$(DSRC)main.c \
		$(DSRC)iso.c
OBJ	=	$(SRC:.c=.o)
INC	=	$(realpath ./include)/
LIB_DIR	=	$(realpath lib)
LIB	=	my
NAME	=	my_world
CFLAGS	=	-Wall -W -Wextra -l c_graph_prog -I $(INC) -g

all: $(NAME)

$(NAME):	$(OBJ)
	#make -C $(LIB_DIR)
	gcc -o $(NAME) $(OBJ) -L $(LIB_DIR) -lmy $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
