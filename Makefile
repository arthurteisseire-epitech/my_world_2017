##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##  Ozz
##

CC	=	gcc
DSRC	=	$(realpath ./src)/
DINIT	=	$(DSRC)init/
DSTATE	=	$(DSRC)states/
DMAP	=	$(DSRC)map/
SRC	=	$(DSRC)main.c \
		$(DMAP)iso.c \
		$(DINIT)init_world.c \
		$(DSTATE)event.c \
		$(DSTATE)update.c \
		$(DSTATE)draw.c \
		$(DSTATE)destroy.c
OBJ	=	$(SRC:.c=.o)
INC	=	$(realpath ./include)/
DLIB	=	$(realpath lib)
LIB	=	my
LIBS	=	-L$(DLIB) -l$(LIB)
NAME	=	my_world
LDFLAGS	=	-lc_graph_prog -lm
CFLAGS	+=	-Wall -W -Wextra -I $(INC) -g

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(LDFLAGS) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
	make clean
